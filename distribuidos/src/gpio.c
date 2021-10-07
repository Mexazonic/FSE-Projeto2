#include "gpio.h"

int ler_gpio(int pin) {
    return digitalRead(pin);
}

void ligar_desligar_gpio(int pin, int signal) {
    digitalWrite(pin, signal);
}

void iniciar_gpio() {
    wiringPiSetup();

    pinMode(LS_T01, OUTPUT);

    pinMode(SJ_T02, INPUT);
    
	pinMode(SF_T, INPUT);
    
	pinMode(SC_IN, INPUT);
    
	pinMode(TEMP_HUM, INPUT);
    
	pinMode(SP_T, INPUT);
    
	pinMode(SPo_T, INPUT);
    
	pinMode(SJ_T01, INPUT);
	
	pinMode(LS_T02, OUTPUT);
    
	pinMode(LC_T, OUTPUT);
    
	pinMode(AC_T, OUTPUT);
    
	pinMode(ASP, OUTPUT);
    
	pinMode(SC_OUT, INPUT);
    
}   

int read_dht_data(setagem *params) {
    
    uint8_t dht_pin = PIN_DHT11_1;

    int data[5] = { 0, 0, 0, 0, 0 };
    float temp_cels = -1;
    float temp_fahr = -1;
    float humidity  = -1;
	uint8_t lastsetagem = HIGH;
	uint8_t counter	= 0;
	uint8_t j = 0;
	uint8_t i;

	data[0] = data[1] = data[2] = data[3] = data[4] = 0;

	/* pull pin down for 18 milliseconds */
	pinMode(dht_pin, OUTPUT);
	digitalWrite(dht_pin, LOW);
	delay(18);

	/* prepare to read the pin */
	pinMode(dht_pin, INPUT);

	/* detect change and read data */
	for ( i = 0; i < MAX_TIMINGS; i++ ) {
		counter = 0;
		while ( digitalRead( dht_pin ) == lastsetagem ) {
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 ) {
				break;
			}
		}
		lastsetagem = digitalRead( dht_pin );

		if ( counter == 255 )
			break;

		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) ) {
			/* shove each bit into the storage bytes */
			data[j / 8] <<= 1;
			if ( counter > 16 )
				data[j / 8] |= 1;
			j++;
		}
	}

	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) && (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) ) {
		float h = (float)((data[0] << 8) + data[1]) / 10;
		if ( h > 100 ) {
			h = data[0];	// for DHT11
		}
		float c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
		if ( c > 125 ) {
			c = data[2];	// for DHT11
		}
		if ( data[2] & 0x80 ) {
			c = -c;
		}
        
        /* Update setagem */
        params->temperatura = c;
		params->humidade = h;
        
        temp_cels = c;
		temp_fahr = c * 1.8f + 32;
        humidity = h;

		if (DEBUG) printf( "read_dht_data() Humidity = %.1f %% Temperature = %.1f *C (%.1f *F)\n", humidity, temp_cels, temp_fahr );
		return 0; // OK
	} else {
		if (DEBUG) printf( "read_dht_data() Data not good, skip\n" );
		temp_cels = temp_fahr = humidity = -1;
		return 1; // NOK
	}
}

void *ativar_atuadores(void *args) {

	setagem *params = (setagem *) args;
	pthread_mutex_t actuator_mutex = PTHREAD_MUTEX_INITIALIZER;

	while(1) {

		pthread_mutex_lock(&actuator_mutex);

		switch (params->codigo_atuador) {
			case LS_T01:
				ligar_desligar_gpio(LS_T01,  params->LS_T01_setagem);
				break;
			case LS_T02:
				ligar_desligar_gpio(LS_T02, params->LS_T02_setagem);
				break;
			case LC_T:
				ligar_desligar_gpio(LC_T, params->LC_T_setagem);
				break;
			case AC_T:
				ligar_desligar_gpio(AC_T, params->AC_T_setagem);
				break;
			case ASP:
				ligar_desligar_gpio(ASP, params->ASP_setagem);
				break;
			
			default:
				break;
		}

		params->codigo_atuador = -1;

		pthread_mutex_unlock(&actuator_mutex);

		sleep(2);
	}
}

void *ler_sensores(void *args) {

	setagem *params = (setagem *) args;
	pthread_mutex_t sensor_mutex = PTHREAD_MUTEX_INITIALIZER;

	while(1) {

		pthread_mutex_lock(&sensor_mutex);

		params->SF_T_setagem = ler_gpio(SF_T);
		printf("Fumaça do Terreo: %d\n", params->SF_T_setagem);
		params->codigo_sensor = SF_T;
		enviar_dados_tcp((void *) params);
		
		params->SP_T_setagem = ler_gpio(SP_T);
		printf("Presenca Terreo: %d\n", params->SP_T_setagem);
		params->codigo_sensor = SP_T;
		enviar_dados_tcp((void *) params);

		params->SJ_T01_setagem = ler_gpio(SJ_T01);
		printf("\nJanela 01 Terreo: %d\n", params->SJ_T01_setagem);
		params->codigo_sensor = SJ_T01;
		enviar_dados_tcp((void *) params);

		params->SPo_T_setagem = ler_gpio(SPo_T);
		printf("Porta de entrada Terreo: %d\n", params->SPo_T_setagem);
		params->codigo_sensor = SPo_T;
		enviar_dados_tcp((void *) params);

		params->SJ_T02_setagem = ler_gpio(SJ_T02);		
		printf("Janela 02 Terreo: %d\n", params->SJ_T02_setagem);
		params->codigo_sensor = SJ_T02;
		enviar_dados_tcp((void *) params);

		read_dht_data(params);
		printf("\nHumidade = %.1f Temperatura = %.1f\n", params->humidade, params->temperatura);
		params->codigo_sensor = TEMP_HUM;
		enviar_dados_tcp((void *) params);

		params->SC_IN_setagem = ler_gpio(SC_IN);
		params->SC_OUT_setagem = ler_gpio(SC_OUT);
		params->pessoas = params->pessoas + params->SC_IN_setagem - params->SC_OUT_setagem;
		params->pessoas = params->pessoas < 0 ? 0 : params->pessoas;

		params->codigo_sensor = PEOPLE_COUNT;

		enviar_dados_tcp((void *) params);

		pthread_mutex_unlock(&sensor_mutex);

		sleep(2);
	}

	return 0;
}
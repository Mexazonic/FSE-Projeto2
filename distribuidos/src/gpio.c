#include "gpio.h"

void iniciar_gpio() {
    wiringPiSetup();
}   

int ler_gpio(int pin) {
    return digitalRead(pin);
}

void escrever_gpio(int pin, int signal) {
    digitalWrite(pin, signal);
}

void ligar_atuadores(setagem *params) {

    if(params->identificador == LS_T01) {
        
        escrever_gpio(LS_T01,  params->LS_T01_setagem);
		printf("\nLS_T01: %d\n", params->LS_T01_setagem);

    } else if(params->identificador == LS_T02) {
        
        escrever_gpio(LS_T02, params->LS_T02_setagem);
		printf("\nLS_T02: %d\n", params->LS_T02_setagem);

    } else if(params->identificador == LC_T) {
    
        escrever_gpio(LC_T, params->LC_T_setagem);
		printf("\nLC_T: %d\n", params->LC_T_setagem);
    
    } else if(params->identificador == AC_T) {
    
        escrever_gpio(AC_T, params->AC_T_setagem);
		printf("\nAC_T: %d\n", params->AC_T_setagem);
    
    } else if(params->identificador == ASP) {
    
        escrever_gpio(ASP, params->ASP_setagem);
		printf("\nASP: %d\n", params->ASP_setagem);
    
    }

}

void *ler_sensores(void *args) {

	setagem *params = (setagem *) args;

	while(1) {

		read_dht_data(params);
		printf("\nHumidade = %.1f%%\n", params->humidade);
        printf("Temperatura = %.1f ºC\n", params->temperatura);
		params->identificador = TEMP_HUM;
		enviar_dado_tcp((void *) params);
		
		params->SP_T_setagem = ler_gpio(SP_T);
		printf("\nSP_T: %d\n", params->SP_T_setagem);
		params->identificador = SP_T;
		enviar_dado_tcp((void *) params);

		params->SPo_T_setagem = ler_gpio(SPo_T);
		printf("\nSPo_T: %d\n", params->SPo_T_setagem);
		params->identificador = SPo_T;
		enviar_dado_tcp((void *) params);

		params->SJ_T01_setagem = ler_gpio(SJ_T01);		
		printf("\nSJ_T01: %d\n", params->SJ_T01_setagem);
		params->identificador = SJ_T01;
		enviar_dado_tcp((void *) params);

		params->SJ_T02_setagem = ler_gpio(SJ_T02);		
		printf("\nSJ_T02: %d\n", params->SJ_T02_setagem);
		params->identificador = SJ_T02;
		enviar_dado_tcp((void *) params);

		params->SF_T_setagem = ler_gpio(SF_T);		
		printf("\nSF_T: %d\n", params->SF_T_setagem);
		params->identificador = SF_T;
		enviar_dado_tcp((void *) params);

		for(int contador = 0; contador < 5; contador++) {

			params->SC_IN_setagem = ler_gpio(SC_IN);
			params->SC_OUT_setagem = ler_gpio(SC_OUT);
			params->pessoas = params->pessoas + params->SC_IN_setagem - params->SC_OUT_setagem;
			params->pessoas = params->pessoas < 0 ? 0 : params->pessoas;

			usleep(200000);
		}

		printf("\nPessoas: %d\n", params->pessoas);
		params->identificador = PESSOAS_IDENTIFICADOR;
		enviar_dado_tcp((void *) params);

		sleep(1);
	}

	return 0;
}

int read_dht_data(setagem *params) {
    
    uint8_t dht_pin = PIN_DHT11_1;  // default GPIO 20 (wiringPi 28)

    int data[5] = { 0, 0, 0, 0, 0 };
    float temp_cels = -1;
    float temp_fahr = -1;
    float humidity  = -1;
	uint8_t laststate = HIGH;
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
		while ( digitalRead( dht_pin ) == laststate ) {
			counter++;
			delayMicroseconds( 1 );
			if ( counter == 255 ) {
				break;
			}
		}
		laststate = digitalRead( dht_pin );

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

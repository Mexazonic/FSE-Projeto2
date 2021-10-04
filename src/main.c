#include <stdio.h>
#include <string.h>
#include "../inc/setagem.h"
#include "../inc/gpio.h"
#include "../inc/dht11.h"
#include "../inc/default.h"


void init_setup();
void close_connections();
void sensores();

int main() {
    
    setagem *params = (setagem *) malloc(sizeof(setagem));

    /* Initial Setup */
	init_setup(params);
    sensores(params);
    
	close_connections();


    return 0;
}

void init_setup(setagem *params) {

    params->run = 0;
    

    params->temperatura = -100.0;
    params->umidade = -100.0;
    params->pessoas = 0;
    params->SC_IN = 0;
    params->SC_OUT = 0;

    params->LS_T01 = 0;
    params->LS_T02 = 1;
    params->LC_T = 1;
    params->AC_T = 0;
    params->ASP = 1;
    params->SP_T = 1;
    params->SF_T = 1;
    params->SJ_T01 = 1;
    params->SJ_T02 = 1;
    params->SPo_T = 1;

  
	usleep(1000000);
}

void close_connections() {
    /* Close GPIO */
    //unbind_gpio();

    close_server();
    close_client();
}




void sensores(setagem *set) {
	read_dht_data(set);

	printf( "Humildade = %.2f%% Temperatura = %.2f ºF\n", set->umidade, set->temperatura);
	
	set->SP_T = read_gpio(SP_T); // Sensor de Presença
	printf("Sensor de presenca Terreo: %d\n", set->SP_T);
	set->SPo_T = read_gpio(SPo_T); // Portaria
	printf("Sensor da porta Terreo: %d\n", set->SPo_T);

	set->SJ_T01 = read_gpio(SJ_T01); // Janela 1 
	printf("Sensor SJ_T01 - Térreo: %d\n", set->SJ_T01);

	set->SJ_T02 = read_gpio(SJ_T02); // Janela 2
	printf("Sensor SJ_T02 - Térreo: %d\n", set->SJ_T02);

	set->SF_T = read_gpio(SF_T); // Fumacê	
	printf("Sensor Fumaça: %d\n", set->SF_T);

	int n = 3;
	while(n--) {

		
		set->SC_IN = read_gpio(SC_IN);
		printf("Entrada: %d\n", set->SC_IN);

		set->SC_OUT = read_gpio(SC_OUT);		
		printf("Sainda: %d\n", set->SC_OUT);

		// Fluxo de Pessoas
		set->pessoas = set->pessoas + set->SC_IN - set->SC_OUT;
		printf("Pessoas no local: %d\n", set->pessoas);

		usleep(200000);
	}

}


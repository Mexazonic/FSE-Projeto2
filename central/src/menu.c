#include "menu.h"

void *carregar_menu(void *args) {

    setagem *params = (setagem *) args;

    menu(params);

    return 0;
}

void menu(setagem *params) {
    
    printf("\n********** Trabalho 2 ********\n\n");
    printf("1-Estado dos sensores e atuadores\n");
    printf("2-Lâmpadas\n");
    printf("3-Ar-condicionado\n");
    printf("4-Alarme de presença\n");
    printf("5-Alarme de incêndio\n");
    printf("\nOpção: ");
    
    int escolha, run;
    int ligar_desligar_flag;

    scanf("%d", &escolha);
    
    switch(escolha) {
        case 1:
            run = 0;
            while(1) {

                if(run != 0) {
                    break;
                }
                printf("\n********** Estado dos sensores e Atuadores ********\n\n");
                
                printf("Lâmpada da Sala T01: %d\n", params->LS_T01_setagem);
                printf("Lâmpada da Sala T02: %d\n", params->LS_T02_setagem);
                printf("Lâmpadas do Corredor Terreo: %d\n", params->LC_T_setagem);
                printf("Ar-Condicionado Terreo: %d\n", params->AC_T_setagem);
                printf("Aspersores de Água (Incêndio): %d\n", params->ASP_setagem);
                printf("Humidade = %.1f\n", params->humidade);
                printf("Temperatura = %.1f\n", params->temperatura);
                printf("Sensor da porta de entrada Terreo: %d\n", params->SPo_T_setagem);
                printf("Sensor de presenca Terreo: %d\n", params->SP_T_setagem);
                printf("Sensor de fumaça do Terreo: %d\n", params->SF_T_setagem);
                printf("Sensor de Janela T01: %d\n", params->SJ_T01_setagem);
                printf("Sensor de Janela T02: %d\n", params->SJ_T02_setagem);
                printf("Sensor de Porta Entrada: %d\n", params->SPo_T_setagem);
                printf("Sensor de Contagem de Pessoas Entrando no Prédio: %d\n", params->SC_IN_setagem);
                printf("Sensor de Contagem de Pessoas Saindo do Prédio: %d\n", params->SC_OUT_setagem);
                printf("Total de pessoas: %d\n", params->pessoas);

                printf("\nPressione 1 para sair: ");

                scanf("%d", &run);
            }

            menu(params);

            break;
        case 2:
            
            printf("\n********** Lampadas ********\n\n");
            printf("1-Lâmpada da Sala T01\n");
            printf("2-Lâmpada da Sala T02\n");
            printf("3-Lâmpadas do Corredor Terreo\n");
            printf("4-Sair\n");
            printf("\nOpção: ");
            
        
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    
                    ligar_desligar();
                    scanf("%d", &ligar_desligar_flag);
                    params->LS_T01_setagem = ligar_desligar_flag;
                    params->codigo_atuador = LS_T01;
                    
                    enviar_dados_tcp((void *) params);

                    atualizar_log("Lâmpada da Sala T01", ligar_desligar_flag);

                    menu(params);
                    
                    break;

                case 2:
                
                    ligar_desligar();
                
                    scanf("%d", &ligar_desligar_flag);
                
                    params->LS_T02_setagem = ligar_desligar_flag;
                    params->codigo_atuador = LS_T02;
                
                    enviar_dados_tcp((void *) params);

                    atualizar_log("Lâmpada da Sala T02", ligar_desligar_flag);

                    menu(params);

                    break;
                case 3:  

                    ligar_desligar();
                
                    scanf("%d", &ligar_desligar_flag);

                    params->LC_T_setagem = ligar_desligar_flag;
                    params->codigo_atuador = LC_T;
                
                    enviar_dados_tcp((void *) params);

                    atualizar_log("Lâmpadas do Corredor Terreo", ligar_desligar_flag);

                    menu(params);

                    break;
                
                case 4:
                    menu(params);
                    break;
                
                default:
                    printf("\nInvalido.\n\n");
                    menu(params);
            }

        break;

        case 3:
            
            printf("\n********** Ar condicionado ********\n\n");

            printf("1-Ar Condicionado do Terreo\n");
            printf("2-Sair\n");
            printf("\nOpção: ");
            

            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    
                    ligar_desligar();
                    scanf("%d", &ligar_desligar_flag);

                    params->AC_T_setagem = ligar_desligar_flag;
                    params->codigo_atuador = AC_T;
                    
                    enviar_dados_tcp((void *) params);

                    atualizar_log("Ar condicionado terreo", ligar_desligar_flag);

                    menu(params);
                    
                    break;
                
                case 3:
                    menu(params);
                    break;
                
                default:
                    printf("\nOpção inválida. Escolha novamente.\n\n");
                    menu(params);
            }

            break;

        case 4:
            
            printf("\n********** Alarme de Presença ********\n\n");
            ligar_desligar();


            scanf("%d", &ligar_desligar_flag);
            
            params->presence_alarm = ligar_desligar_flag;
            params->codigo_atuador = ALARME_PRESENCA;
            
            enviar_dados_tcp((void *) params);

            atualizar_log("ALARME_PRESENÇA", ligar_desligar_flag);

            menu(params);

            break;
        case 5:
            
            printf("\n********** Alarme de Incendio ********\n\n");
            ligar_desligar();


            scanf("%d", &ligar_desligar_flag);
            
            params->fire_alarm = ligar_desligar_flag;
            params->codigo_atuador = ALARME_FOGO;
            
            enviar_dados_tcp((void *) params);

            atualizar_log("ALARME_INCENDIO", ligar_desligar_flag);

            menu(params);

            break;

        default:
            printf("\nOpção inválida. Escolha novamente.\n\n");
            menu(params);
    }
}


void ligar_desligar() {

    printf("\n********** Ligar/Desligar ********\n\n");
    printf("0) Desligar\n");
    printf("1) Ligar\n");
    printf("Opcao: ");
}
#include "setagem.h"

int main() {
    signal(SIGINT, fechar);
    params = (setagem *) malloc(sizeof(setagem));
    iniciar(params);
    pthread_create(&sensores_th, NULL, ler_sensores, (void *) &params);
    pthread_create(&th_servidor, NULL, iniciar_servidor, (void *) &params);
    pthread_create(&atuadores_th, NULL, ativar_atuadores, (void *) &params);

    pthread_join(sensores_th, NULL);
    pthread_join(th_servidor, NULL);
    pthread_join(atuadores_th, NULL);
    return 0;
}


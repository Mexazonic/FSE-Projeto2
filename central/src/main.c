#include "setagem.h"

int main() {
    signal(SIGINT, fechar);
    params = (setagem *) malloc(sizeof(setagem));
    iniciar(params);
    pthread_create(&th_servidor, NULL, iniciar_servidor, (void *) &params);
    pthread_create(&menu_thread, NULL, carregar_menu, (void *) &params);
    pthread_join(th_servidor, NULL);
    pthread_join(menu_thread, NULL);
    return 0;
}

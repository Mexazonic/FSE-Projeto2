#include "setagem.h"
#include "config.h"

int main() {

    signal(SIGINT, fechar);
    char aux[5000];
    void * temp = &aux[0];

    estado = (setagem *) temp;
    iniciar(estado);

    pthread_create(&thread_servidor, NULL, iniciar_servidor_distribuido, (void *) &estado);
    pthread_create(&thread_menu, NULL, carregar_menu, (void *) &estado);
    pthread_join(thread_servidor, NULL);
    pthread_join(thread_menu, NULL);

    return 0;
}


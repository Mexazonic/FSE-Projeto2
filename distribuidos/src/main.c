#include "setagem.h"
#include "config.h"

int main() {

    signal(SIGINT, encerrar);

    char aux[5000];
    void *temp = &aux[0];
    estado = (setagem * ) temp;
    iniciar(estado);

    pthread_create(&thread_servidor, NULL, iniciar_servidor_distribuido, NULL);
    pthread_create(&thread_leitura_sensores, NULL, ler_sensores, (void *) &estado);
    pthread_join(thread_servidor, NULL);
    pthread_join(thread_leitura_sensores, NULL);

    return 0;
}


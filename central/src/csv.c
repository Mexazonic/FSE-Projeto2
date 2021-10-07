 
#include "csv.h"

void atualizar_log(char * command, int value)
{
    FILE *f;
    f = fopen("comandos.csv", "a");

    time(&seed);

    args = localtime(&seed);

    strftime(datetime, 80, "%d/%m/%Y, %H:%M:%S", args);

    fprintf(f, "%s, %s, %d\n", datetime, command, value);
    fclose(f);
}

void criar_arquivo()
{
    FILE *f;

    f = fopen("comandos.csv", "w");
    fprintf(f, "Data, Hora, Comando, Valor\n");
    fclose(f);
}

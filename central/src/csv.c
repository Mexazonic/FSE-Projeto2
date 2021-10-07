 
#include "csv.h"

void init_csv()
{
    FILE *f;

    f = fopen("log.csv", "w");
    fprintf(f, "Data, Hora, Comando, Valor\n");
    fclose(f);
}

void atualizar_log(char * command, int value)
{
    FILE *f;
    f = fopen("log.csv", "a");

    time(&seed);

    args = localtime(&seed);

    strftime(datetime, 80, "%d/%m/%Y, %H:%M:%S", args);

    fprintf(f, "%s, %s, %d\n", datetime, command, value);
    fclose(f);
}
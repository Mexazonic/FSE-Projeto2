#ifndef SETAGEM_H_
#define SETAGEM_H_

typedef struct {
    int run;

    // Humildade e Temperatura
    float temperatura;
    float umidade;

    // Pessoas
    int pessoas;
    int SC_IN;
    int SC_OUT;

// Andare
    int LS_T01;
    int LS_T02;
    int LC_T;
    int AC_T;
    int ASP;

    int SP_T;
    int SF_T;
    int SJ_T01;
    int SJ_T02;
    int SPo_T;

   
} setagem;

#endif /* SET_PARAMS_ */
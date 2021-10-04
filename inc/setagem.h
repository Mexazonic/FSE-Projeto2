#ifndef SETAGEM_H_
#define SETAGEM_H_




typedef struct {
    int run;

    // Humildade e Temperatura
    float temperatura;
    float umidade;

    // Pessoas
    int pessoas;
    int SC_IN_estado;
    int SC_OUT_estado;

// Andare
    int LS_T01_estado;
    int LS_T02_estado;
    int LC_T_estado;
    int AC_T_estado;
    int ASP_estado;

    int SP_T_estado;
    int SF_T_estado;
    int SJ_T01_estado;
    int SJ_T02_estado;
    int SPo_T_estado;

   
} setagem;

#endif /* SET_PARAMS_ */
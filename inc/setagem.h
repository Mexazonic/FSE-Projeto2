#ifndef SETAGEM_H_
#define SETAGEM_H_


#define LS_T01 7 
#define LS_T02 0 
#define LC_T 27 
#define AC_T 11 
#define ASP 16 


#define SP_T 25 

#define SF_T 4 

#define SJ_T01 13 
#define SJ_T02 14 

#define SPo_T 12 

#define SC_IN 23 

#define SC_OUT 24 


typedef struct {
    int run;

    // Humildade e Temperatura
    float temperatura;
    float umidade;

    // Pessoas
    int pessoas;
    int SC_IN = 20;
    int SC_OUT = 10;

// Andare
    int LS_T01 = 7;
    int LS_T02 = 0;
    int LC_T = 27;
    int AC_T = 11;
    int ASP = 16;

    int SP_T = 25;
    int SF_T = 4;
    int SJ_T01 = 13;
    int SJ_T02 = 14;
    int SPo_T = 12;

   
} setagem;

#endif /* SET_PARAMS_ */
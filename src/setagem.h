#ifndef SET_PARAMS_
#define SET_PARAMS_

typedef struct {
    // /* Init/Stop system */
    int run;

    /* Humidity and temperatura */
    float temperatura;
    float umidade;

    // /* People Amount */
    int pessoas;
    int SC_IN;
    int SC_OUT;

    /* Ground Floor Actuators State*/
    int LS_T01;
    int LS_T02;
    int LC_T;
    int AC_T;
    int ASP;

    /* Ground Floor Actuators State*/
    int SP_T;
    int SF_T;
    int SJ_T01;
    int SJ_T02;
    int SPo_T;

    // /* First Floor State */
    // int LS_101;
    // int LS_102;
    // int LC_1;
    // int AC_1;
    // int SP_1;
    // int SF_1;
    // int SJ_1;
    // int SJ_2;
    
} setagem;

#endif /* STATE_H_ */
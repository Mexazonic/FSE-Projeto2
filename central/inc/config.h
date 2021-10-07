#ifndef _CONFIG_H
#define _CONFIG_H

typedef struct {
    float temperatura;
    float humidade;
    int pessoas;
    int SC_IN_setagem;
    int SC_OUT_setagem;
    int presence_alarm;
    int fire_alarm;
    int LS_T01_setagem;
    int LS_T02_setagem;
    int LC_T_setagem;
    int AC_T_setagem;
    int ASP_setagem;
    int SP_T_setagem;
    int SF_T_setagem;
    int SJ_T01_setagem;
    int SJ_T02_setagem;
    int SPo_T_setagem;
    int identificador;

} setagem;

#endif
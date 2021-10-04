#ifndef DEFAULT_H_
#define DEFAULT_H_

/* Ground Floor */
#define LS_T01 7 // GPIO 04, Wiringpi 7
#define LS_T02 0 // GPIO 17, Wiringpi 0
#define LC_T 27 // GPIO 27, Wiringpi 2
#define AC_T 11 // GPIO 7, Wiringpi 11
#define ASP 16 // GPIO 16, Wiringpi 27

#define SP_T 25 // GPIO 26, Wiringpi 25
#define SF_T 4 // GPIO 23, Wiringpi 13
#define SJ_T01 13 // GPIO 9, Wiringpi 13
#define SJ_T02 14 // GPIO 11, Wiringpi 14
#define SPo_T 12 // GPIO 10, Wiringpi 12
#define SC_IN 23 // GPIO 13, Wiringpi 23
#define SC_OUT 24 // GPIO 19, Wiringpi 24

/* First Floor */
#define LS_101 22
#define LS_102 25
#define LC_1 08
#define AC_1 12
#define SP_1 18
#define SF_1 24
#define SJ_1 05
#define SJ_2 06

/* DHT11 */
#define PIN_DHT11_1 28 // GPIO 20, Wiringpi 28
#define PIN_DHT11_2 29 // GPIO 21, Wiringpi 29

/* Ports */
#define CENTRAL_SERVER_PORT 10010
#define DISTRIBUTED_SERVER_1_PORT 10110
#define DISTRIBUTED_SERVER_2_PORT 10210

/* IP */
#define DISTRIBUTED_SERVER_IP "192.168.0.22"
#define CENTRAL_SERVER_IP "192.168.0.53"


#endif /* DEFAULT_H_ */
#ifndef OPENDEV_H
#define OPENDEV_H

#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_BUFF_SIZE (246)

typedef struct _serial_parse{
    char buff[MAX_BUFF_SIZE];
    int rxbuffsize;
}serial_parse;

int openDev(char *Dev){};
void set_speed(int fd, int speed){};
int set_parity(int fd, int databits, int stopbits, int parity){};
int analysis(char *buff){};
#endif
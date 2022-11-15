#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "/home/polaris/projects/gps_c/include/openDev.h"

int main() {
    int fd;
    int nread;
    char buffer[MAX_BUFF_SIZE];

    serial_parse phandle;
    phandle.rxbuffsize = 0;

    char *dev_name = "/dev/ttymxc4";

    while(1){
        fd = openDev(dev_name);

        if (fd > 0){
            set_speed(fd, 57600);
            printf("Set speed success!\n");
        } else {
            printf("Can't Open Serial Port!\n");
            sleep(1);
            continue;
        }
        break;
    }
    if (set_parity(fd, 8, 1, 'N')==FALSE){
        printf("Set Parity Error\n");
        exit(1);
    } else {
        printf("Set Parity Success!\n");
    }

    while(1){
        usleep(10000);
        nread = read(fd, phandle.buff + phandle.rxbuffsize, MAX_BUFF_SIZE-phandle.rxbuffsize);
        phandle.rxbuffsize += nread;
        phandle.buff[phandle.rxbuffsize] = '\0';
        /*
            数据处理
        */
       analysis(buffer);
    }
    return 0;
}


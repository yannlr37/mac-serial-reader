//
//  serial.c
//  MacSerialParser
//
//  Created by yann on 07/09/2024.
//  Copyright (c) 2024 sheepdev. All rights reserved.
//

#include "serial.h"

/**
 * C code for configuring and opening a Serial Port on a UNIX device
 */
int c_openSerialPort(const char *device, int nBaudRate, int nParity, int nDataBits, int nStopBits )
{
    // open serial device
    int fd = open(device, O_RDWR | O_NOCTTY | O_NDELAY);
    
    if (fd == -1) {
        return fd;
    }
    
    struct termios options;
    
    tcgetattr(fd, &options);
    
    // define intput and output Baud Rate
    cfsetispeed(&options, B9600);
    cfsetospeed(&options, B9600);
    
    // define data bites
    // remove bits for caracters'size
    options.c_cflag &= ~CSIZE;
    switch(nDataBits)
    {
        case 5: options.c_cflag |= CS5; break;
        case 6: options.c_cflag |= CS6; break;
        case 7: options.c_cflag |= CS7; break;
        case 8: options.c_cflag |= CS8; break;
        default:
            return -2;
    }
    
    // define stop bits
    switch(nStopBits)
    {
        case 1: options.c_cflag |= ~CSTOPB; break;
        case 2: options.c_cflag |= CSTOPB; break;
        default:
            return -3;
    }
    
    // define parity
    switch(nParity)
    {
        case 0: options.c_cflag |= ~PARENB; break;
        case 1:
            options.c_cflag |= PARENB;
            options.c_cflag &= ~PARODD;
            break;
        case 2:
            options.c_cflag |= PARENB;
            options.c_cflag |= PARODD;
            break;
        default:
            return -4;
    }
    
    // activate reading mode, avoid modem control
    options.c_cflag |= (CLOCAL | CREAD);
    
    tcsetattr(fd, TCSANOW, &options);
    
    return fd;
}

/**
 * Read from serial port and store raw data into a buffer
 */
ssize_t c_readFromSerialPort(int fd, void* buffer, size_t bufferLength)
{
    return read(fd, buffer, bufferLength);
}

/**
 * Properly close serial connection
 */
void c_closeSerialPort(int fd)
{
    close(fd);
}

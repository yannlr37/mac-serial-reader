//
//  serial.h
//  MacSerialParser
//
//  Created by yann on 07/09/2024.
//  Copyright (c) 2024 sheepdev. All rights reserved.
//

#ifndef MacSerialParser_serial_h
#define MacSerialParser_serial_h

#include <stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

int c_openSerialPort(const char *device, int nBaudRate, int nParity, int nDataBits, int nStopBits);

ssize_t c_readFromSerialPort(int fd, void* buffer, size_t bufferLength);

void c_closeSerialPort(int fd);

#endif

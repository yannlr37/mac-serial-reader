//
//  SerialPort.m
//  MacSerialParser
//
//  Created by yann on 06/09/2024.
//  Copyright (c) 2024 sheepdev. All rights reserved.
//

#import "SerialPort.h"
#import "serial.h"

/* -------------------------------------------------------------------------- */
// C code for dealing with serial port
/* -------------------------------------------------------------------------- */



/* -------------------------------------------------------------------------- */
// CLASS IMPLEMENTATION
/* -------------------------------------------------------------------------- */

@implementation SerialPort

@synthesize comPort         = _comPort;
@synthesize baudRate        = _baudRate;
@synthesize parity          = _parity;
@synthesize dataBits        = _dataBits;
@synthesize stopBits        = _stopBits;
@synthesize handle          = _handle;
@synthesize buffer          = _buffer;
@synthesize bufferLength    = _bufferLength;

/**
 * Default init method: no configuration required
 * Takes the default serial parameters (Baud 9600, 8 bits data, 0 bit stop, no parity)
 */
- (id) init:(NSString*) comPort
{
    return [self initWithComPort:comPort
                     andBaudRate:BAUD9600
                       andParity:PARITY_NONE
                     andDataBits:8
                      andStopBit:0];
}

/**
 * User-defined serial connection configuration
 */
- (id) initWithComPort:(NSString*) comPort
             andBaudRate:(NSInteger) baudRate
               andParity:(NSInteger) parity
             andDataBits:(NSInteger) dataBits
              andStopBit:(NSInteger) stopBits
{
    if (self = [super init]) {
        _comPort = comPort;
        _baudRate = baudRate;
        _parity = parity;
        _dataBits = dataBits;
        _stopBits = stopBits;
    }
    return self;
}


- (BOOL) connect
{
    @try {
        _handle = c_openSerialPort([_comPort UTF8String],
                                 _baudRate,
                                 _dataBits,
                                 _stopBits,
                                 _parity);
        
        if (_handle < 0) {
            if (_handle == -1)
                NSLog(@"Cannot connect to %@ serial COM port", _comPort);
            if (_handle == -2)
                NSLog(@"Cannot connect to %@ serial COM port. DataBits value is not allowed.", _comPort);
            if (_handle == -3)
                NSLog(@"Cannot connect to %@ serial COM port. StopBits value is not allowed.", _comPort);
            if (_handle == -4)
                NSLog(@"Cannot connect to %@ serial COM port. Parity value is not allowed.", _comPort);
            return FALSE;
        }
        
        return TRUE;
    }
    @catch(NSException *e) {
        NSLog(@"Serial Port %@ cannot connect : %@", _comPort, e);
        return FALSE;
    }
}

- (NSData*) read
{
    // TODO: implement this method
    return nil;
}

- (void) debug
{
    // TODO: implement this method
}

@end

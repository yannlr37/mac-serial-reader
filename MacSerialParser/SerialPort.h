//
//  SerialPort.h
//  MacSerialParser
//
//  Created by yann on 06/09/2024.
//  Copyright (c) 2024 sheepdev. All rights reserved.
//

#import <Foundation/Foundation.h>

/* -------------------------------------------------------------------------- */
// STRUCTURES and ENUMERATIONS
/* -------------------------------------------------------------------------- */

typedef NS_ENUM(NSInteger, e_parity)
{
    PARITY_NONE = 0,
    PARITY_EVEN = 1,
    PARITY_ODD = 2
};

typedef NS_ENUM(NSInteger, e_baudRate)
{
    BAUD4800 = 4800,
    BAUD9600 = 9600,
    BAUD115200 = 115200
};

typedef NS_ENUM(NSInteger, e_dataBits)
{
    DATA_5 = 5,
    DATA_6 = 6,
    DATA_7 = 7,
    DATA_8 = 8
};

typedef NS_ENUM(NSInteger, e_stopBits)
{
    STOP_1 = 1,
    STOP_2 = 2
};

/* -------------------------------------------------------------------------- */
// CLASS DEFINITION
/* -------------------------------------------------------------------------- */

@interface SerialPort : NSObject
{
    
}

@property (nonatomic, assign) NSString*             comPort;
@property (nonatomic, assign) e_baudRate            baudRate;
@property (nonatomic, assign) e_parity              parity;
@property (nonatomic, assign) e_dataBits            dataBits;
@property (nonatomic, assign) e_stopBits            stopBits;
@property (nonatomic, nonatomic) int                handle;
@property (nonatomic, assign) NSMutableArray*       buffer;
@property (nonatomic, nonatomic) int                bufferLength;


- (id) initWithComPort:(NSString*) comPort;

- (id) initWithComPort:(NSString*) comPort
             andBaudRate:(NSInteger) baudRate
                andParity:(NSInteger) parity
              andDataBits:(NSInteger) dataBits
               andStopBit:(NSInteger) stopBits;

- (BOOL) connect;

- (NSData*) read;

- (void) debug;

@end

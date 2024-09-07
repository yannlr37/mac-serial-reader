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
    PARITY_EVEN,
    PARITY_ODD
};

typedef NS_ENUM(NSInteger, e_baudRate)
{
    BAUD4800 = 4800,
    BAUD9600 = 9600,
    BAUD115200 = 115200
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
@property (nonatomic, nonatomic) int                dataBits;
@property (nonatomic, nonatomic) int                stopBits;
@property (nonatomic, assign) NSMutableArray*       buffer;
@property (nonatomic, nonatomic) int                bufferLength;


- (id) initWithComPort:(NSString*) comPort;

- (id) initWithComPort:(NSString*) comPort
             andBaudRate:(NSInteger) baudRate
                andParity:(NSInteger) parity
              andDataBits:(int) dataBits
               andStopBit:(int) stopBits;

- (BOOL) connect;

- (NSData*) read;

- (void) debug;

@end

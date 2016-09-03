#ifndef GLOBALS_H
#define GLOBALS_H

//#define __16f628a
#include "pic16f628a.h"


#define SETPORTBIT(Port,bit)	Port|=(1<<bit);
#define CLEARPORTBIT(Port,bit)	Port&=~(1<<bit);
#define READPORTBIT(Port,bit)	(Port&(1<<bit))?1:0;
#define TOGGLEBIT(Port,bit)		Port=Port^(1<<bit);

typedef unsigned char u8;
typedef unsigned int u16;

#include "UART.h"
#include "SPI.h"
#include "mailcommand.h"


#define POWER_ACT_LED   RB0

#endif

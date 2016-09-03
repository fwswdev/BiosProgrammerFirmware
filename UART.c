#include "globals.h"


volatile u8 UART_Data_Array[UARTBUF_SZ+5];
volatile u8 UARTPtrIn,UARTPtrOut;


void SCI_Init(void)
{
GIE=1;
PEIE=1;
RCIE=1;
TRISB1=1;
TRISB2=1;
TXSTA=0x26;
RCSTA=0x90;
//SPBRG=71;
SPBRG=9; // 115200 @ 18.432MHz Crystal
UARTBUFRESET

//SPBRG=71; // 9600 @ 11MHz crystal hi speed
//SPBRG=0x05; // 115200 @ 11MHz crystal hi speed
//SPBRG=0x11; // 38400 @ 11MHz crystal hi speed
//SPBRG=11; // 57600 @ 11MHz crystal hi speed
//SPBRG=15; // 38400 @ 10MHz crystal hi speed
}




void SCI_Transmit(u8 Data)
{
while(!TRMT);
TXREG=Data;
}




u16 SCI_Receive(void)
{
static u16 Timer1,Timer2;
static u8 RXData;
Timer1=0;
Timer2=0;
while(UARTPtrIn==UARTPtrOut)
    {
    Timer1++;
    if(Timer1>50000)
        Timer2++;
    if(Timer2>5)
        {
        return 256;
        }
    }
RXData=UART_Data_Array[UARTPtrOut];
UARTPtrOut++;
if(UARTPtrOut>UARTBUF_SZ)
    UARTPtrOut=0;
return RXData;
}



void CheckSCIError(void)
{
if(FERR)
    {
    u8 Data;
    Data=RCREG;   
    }
if(OERR)
    {
    CREN=0;
    CREN=1;   
    }
}


void Intr(void) __interrupt 0
{
if(RCIF)
    {
    UART_Data_Array[UARTPtrIn]=RCREG;
    UARTPtrIn++;
    if(UARTPtrIn>UARTBUF_SZ)
        UARTPtrIn=0;
    RA0=!RA0;
    }
}


//

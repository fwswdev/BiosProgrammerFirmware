#include "globals.h"

#define SPI_Delay() __asm__ ("nop");
/*
static void SPI_Delay(void);


static void SPI_Delay(void)
{
    
//u8 ctr;
//ctr=10;
//while(ctr--);   

_asm nop _endasm;
//_asm nop _endasm;
//_asm nop _endasm;
}
*/



void SPI_CS_On(void)
{
SPI_CS=1;
SPI_CS_INV=0;
SPI_Delay();
}


void SPI_CS_Off(void)
{
SPI_CS=0;   
SPI_CS_INV=1; 
SPI_Delay();
}


void SPI_Init(void)
{
//TRISA=0x02;
SPI_CS_Off();
SPI_MOSI=0;
SPI_MISO=0;
SPI_CLK=0;
}



u8 SPI_Transmit(u8 Data)
{
static u8 ctr,Ret_Data;
Ret_Data=0;
ctr=7;
do
    {
    /*
    if((Data>>ctr)&0x01)
        SPI_MOSI=1;
    else
        SPI_MOSI=0;
    */
    SPI_MOSI=0;
    if(Data&0x80) SPI_MOSI=1;
    Data=((Data << 1) | (Data >> 7));
    SPI_Delay();
    SPI_CLK=1;
    SPI_Delay();
    if(SPI_MISO==1)
        Ret_Data|=(1<<ctr);
    SPI_CLK=0;
//    SPI_Delay();
//    if(SPI_MISO==1)
//        Ret_Data|=(1<<ctr);
    ctr--;
    }while(ctr!=0xFF);
return Ret_Data;
}

#include "globals.h"

#define SPI_Delay() __asm__ ("nop");


void SPI_CS_On(void)
    {
    SPI_CS = 1;
    SPI_CS_INV = 0;
    SPI_Delay()
    ;
    }

void SPI_CS_Off(void)
    {
    SPI_CS = 0;
    SPI_CS_INV = 1;
    SPI_Delay()
    ;
    }

void SPI_Init(void)
    {
//TRISA=0x02;
    SPI_CS_Off();
    SPI_MOSI = 0;
    SPI_MISO = 0;
    SPI_CLK = 0;
    }

// SPI (bitbang)
u8 SPI_Transmit(u8 Data)
    {
    // we declare everything static to avoid repeated stack allocation
    static u8 sctr, sRet_Data;
    sRet_Data = 0;
    sctr = 7;
    do
	{
	SPI_MOSI = 0;
	if (Data & 0x80)
	    SPI_MOSI = 1;
	Data = ((Data << 1) | (Data >> 7));
	SPI_Delay()
	;
	SPI_CLK = 1;
	SPI_Delay()
	;
	if (SPI_MISO == 1)
	    sRet_Data |= (1 << sctr);
	SPI_CLK = 0;
	sctr--;
	}
    while (sctr != 0xFF);
    return sRet_Data;
    }

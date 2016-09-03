#ifndef SPI_H
#define SPI_H

//void SPI_Delay(void);

void SPI_Init(void);
u8 SPI_Transmit(u8 Data);

void SPI_CS_On(void);
void SPI_CS_Off(void);


//#define SPI_MOSI    RB3//RA0
#define SPI_MOSI    RA0
#define SPI_MISO    RA4
#define SPI_CLK     RA2
#define SPI_CS      RA3
#define SPI_CS_INV  RA1

#endif

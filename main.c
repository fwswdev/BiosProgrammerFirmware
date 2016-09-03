/* ===================
00.08.00
    - First Release
00.08.01
    - Development Testing
00.08.02
    - Working. This was used for writing and reading the BIOS successfully.
00.08.03
    - Code Improvement
===================== */

#include "globals.h"

// Configurations
static __code u16  __at (0x2007) configword1 = _HS_OSC & _PWRTE_OFF & _WDT_OFF & _BODEN_OFF & _CP_OFF & _LVP_OFF & _MCLRE_ON;
    
    
static const char *const TITLE_OF_PROGRAM=
    "BIOS Flasher 00.08.03 "
    "By: Jeff "
    ;

void PIC_Init(void);


void main(void) {
PIC_Init();
SCI_Init();
SPI_Init();

while(1)
	{
    POWER_ACT_LED=1;
    if(UARTPtrIn!=UARTPtrOut)
        {
        MailCommand_Receive();
        }
    CheckSCIError();
	}
}



void PIC_Init(void)
{
INTCON=0x00;
OPTION_REG=0x00;
PORTA=0x00;
PORTB=0x00;
TRISA=0x10;
TRISB=0x00;
}


//void Inject()
//{
//UARTBUFRESET
//UART_Data_Array[UARTPtrIn++]=0x10;
//UART_Data_Array[UARTPtrIn++]=4;
//UART_Data_Array[UARTPtrIn++]=0x10;
//UART_Data_Array[UARTPtrIn++]=1;
//UART_Data_Array[UARTPtrIn++]=0;
//UART_Data_Array[UARTPtrIn++]=6;
//UART_Data_Array[UARTPtrIn++]=0x2B;
//}


/*    
    MYDELAY(ctr);
//    PORTA=~PORTA;
//    SCI_Transmit('g');
//    SCI_Transmit('w');
//    SCI_Transmit('a');
     //if(SCI_Receive()=='x')
     //   RA1=!RA1;
   
     SPI_CS_On();
     SPI_Transmit(0x05);
     SPI_Transmit(0xFF);
     SPI_Transmit(0xFF);          
     SPI_CS_Off();
*/
    //inject data
    
    //Inject();
    
    //

//

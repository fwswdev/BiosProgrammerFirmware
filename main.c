/* ===================
 00.08.00
 - First Release
 00.08.01
 - Development Testing
 00.08.02
 - Working. This was used for writing and reading the BIOS successfully.
 00.08.03
 - Code Improvement
 00.08.04 (03-Sept-2016)
 - Public release.
 - Modified to work with the latest SDCC 3.6.0 x64 and gputil 1.5.0
 - In this situation,I used lots of static variable to avoid
 repeated stack allocation.
 ===================== */

#include "globals.h"

// Configurations
static __code u16 __at (0x2007) configword1 = _HS_OSC & _PWRTE_OFF & _WDT_OFF & _BODEN_OFF & _CP_OFF & _LVP_OFF & _MCLRE_ON;

static const char * const TITLE_OF_PROGRAM =
	"BIOS Flasher 00.08.03 "
	"By: Jeff ";

void PIC_Init(void);

void main(void)
    {
    PIC_Init();
    SCI_Init();
    SPI_Init();

    while (1)
	{
	POWER_ACT_LED = 1;
	if (UARTPtrIn != UARTPtrOut)
	    {
	    MailCommand_Receive();
	    }
	CheckSCIError();
	}
    }

void PIC_Init(void)
    {
    INTCON = 0x00;
    OPTION_REG = 0x00;
    PORTA = 0x00;
    PORTB = 0x00;
    TRISA = 0x10;
    TRISB = 0x00;
    }

// end of file

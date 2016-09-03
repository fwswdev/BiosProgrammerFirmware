#ifndef MAILCOMMAND_H
#define MAILCOMMAND_H

#define HEADER_FRAME    0x10

#define NO_ERROR    0
#define ERROR       1
void MailCommand_Receive(void);


enum MAILCOMMANDS
{
    SPI_TRANSMIT_RECEIVE=0x10  
};

#endif

#include "globals.h"




void MailCommand_Receive(void)
{
static u16 ReceivedData;
static u8 checksum,ctr,MailCommandReceived;
static u8 ArrayBuffer[UARTBUF_SZ+5],DataLength;


checksum=0;
ReceivedData=SCI_Receive();
if(ReceivedData!=HEADER_FRAME) return;
if(ReceivedData==256) return;

ReceivedData=SCI_Receive();
if(ReceivedData==256) return;
DataLength=ReceivedData;

checksum=HEADER_FRAME+DataLength;

for(ctr=0;ctr<DataLength;ctr++)
    {
    ReceivedData=SCI_Receive();
    if(ReceivedData==256) return;
    ArrayBuffer[ctr]=ReceivedData;
    checksum+=ReceivedData;
    }
    
ReceivedData=SCI_Receive();
if(ReceivedData==256) return;
if(checksum!=ReceivedData) return;

POWER_ACT_LED=0;
MailCommandReceived=ArrayBuffer[0];

if(SPI_TRANSMIT_RECEIVE==MailCommandReceived)
    {
    static u8 TXLen,RXLen;
    TXLen=ArrayBuffer[1];
    RXLen=ArrayBuffer[2];
    
    SPI_CS_On();
    
    //transmit
    for(ctr=0;ctr<TXLen;ctr++)
        {
        SPI_Transmit(ArrayBuffer[ctr+3]);
        }
    
    SCI_Transmit(NO_ERROR);
    
    //receive
    for(ctr=0;ctr<RXLen;ctr++)
        {
        SCI_Transmit(SPI_Transmit(0xFF));
        }
    SPI_CS_Off();        
    return; //immediate exit
    }
}



////////////////////////////////

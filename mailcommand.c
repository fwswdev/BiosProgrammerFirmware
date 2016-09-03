#include "globals.h"


void MailCommand_Receive(void)
    {
    // we declare everything static to avoid repeated stack allocation
    static u16 sReceivedData;
    static u8 sChecksum, ctr, sMailCommandReceived;
    static u8 sArrayBuffer[UARTBUF_SZ + 5], sDataLength;

    sChecksum = 0;
    sReceivedData = SCI_Receive();
    if (sReceivedData != HEADER_FRAME)
	return;
    if (sReceivedData == 256)
	return;

    sReceivedData = SCI_Receive();
    if (sReceivedData == 256)
	return;
    sDataLength = sReceivedData;

    sChecksum = HEADER_FRAME + sDataLength;

    for (ctr = 0; ctr < sDataLength; ctr++)
	{
	sReceivedData = SCI_Receive();
	if (sReceivedData == 256)
	    return;
	sArrayBuffer[ctr] = sReceivedData;
	sChecksum += sReceivedData;
	}

    sReceivedData = SCI_Receive();
    if (sReceivedData == 256)
	return;
    if (sChecksum != sReceivedData)
	return;

    POWER_ACT_LED = 0;
    sMailCommandReceived = sArrayBuffer[0];

    if (SPI_TRANSMIT_RECEIVE == sMailCommandReceived)
	{
	static u8 TXLen, RXLen;
	TXLen = sArrayBuffer[1];
	RXLen = sArrayBuffer[2];

	SPI_CS_On();

	//transmit
	for (ctr = 0; ctr < TXLen; ctr++)
	    {
	    SPI_Transmit(sArrayBuffer[ctr + 3]);
	    }

	SCI_Transmit(NO_ERROR);

	//receive
	for (ctr = 0; ctr < RXLen; ctr++)
	    {
	    SCI_Transmit(SPI_Transmit(0xFF));
	    }
	SPI_CS_Off();
	return; //immediate exit
	}
    }

////////////////////////////////

#ifndef UART_H
#define UART_H

#define UARTBUF_SZ      35
#define UARTBUFRESET    UARTPtrIn=0;UARTPtrOut=0;

extern volatile u8 UART_Data_Array[];
extern volatile u8 UARTPtrIn,UARTPtrOut;

void SCI_Init(void);
void SCI_Transmit(u8 Data);
u16 SCI_Receive(void);
void CheckSCIError(void);

#endif

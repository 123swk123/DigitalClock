/*
 * Comm_UART.cpp
 *
 * Created: 25-05-2016 02:04:07
 *  Author: karthikeyan
 */ 
#include <avr/io.h>
#include "Comm_UART.h"

cComm_UART::cComm_UART()
{
  // USART initialization
  // Communication Parameters: 8 Data, 1 Stop, No Parity
  // USART Receiver: On
  // USART Transmitter: On
  // USART Mode: Asynchronous
  // USART Baud Rate: 38400
  UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
  UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
  UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
  UBRR0H=0x00;
  UBRR0L=0x0C;
}

bool cComm_UART::Send(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  while (u8Size--)
  {
    /*Wait till UART transmit buffer is available*/
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = *u8ptrData++;
  }

  return true;
}

bool cComm_UART::Receive(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  while (u8Size--)
  {
    /*Wait till UART receive buffer is available*/
    while (!(UCSR0A & (1 << RXC0)));
    *u8ptrData++ = UDR0;
  }

  return true;
}

/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* Comm_UART.cpp is part of Digital Clock.
*
* Digital Clock is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* Digital Clock is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Digital Clock.  If not, see <http://www.gnu.org/licenses/>.
************************************************************************/

#include <avr/io.h>
#include "Comm_UART.h"

cComm_UART::cComm_UART()
{
  // USART initialization
  // Communication Parameters: 8 Data, 1 Stop, No Parity
  // USART Receiver: On
  // USART Transmitter: On
  // USART Mode: Asynchronous
  // USART Baud Rate: 57600 (Double Speed Mode)
  UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (1<<U2X0) | (0<<MPCM0);
  UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (1<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
  UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
  UBRR0H=0x00;
  UBRR0L=0x22;
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

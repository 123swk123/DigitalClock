/*
 * Comm_UART.h
 *
 * Created: 25-05-2016 02:08:56
 *  Author: karthikeyan
 */ 


#ifndef COMM_UART_H_
#define COMM_UART_H_

#include "Comm_Abstract.h"

class cComm_UART : public cComm_Driver
{
  public:
  cComm_UART();
  virtual bool Send(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
  virtual bool Receive(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
};



#endif /* COMM_UART_H_ */
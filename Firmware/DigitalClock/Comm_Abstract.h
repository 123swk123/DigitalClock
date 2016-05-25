/*
 * Comm_Abstract.h
 *
 * Created: 25-05-2016 02:05:25
 *  Author: karthikeyan
 */ 


#ifndef COMM_ABSTRACT_H_
#define COMM_ABSTRACT_H_

#include <stdint.h>

class cComm_Driver
{
  public:
  virtual bool Send(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size) = 0;
  virtual bool Receive(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size) = 0;
};



#endif /* COMM_ABSTRACT_H_ */
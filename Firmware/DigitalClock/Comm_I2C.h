/*
 * Comm_I2C.h
 *
 * Created: 25-05-2016 02:12:36
 *  Author: karthikeyan
 */ 


#ifndef COMM_I2C_H_
#define COMM_I2C_H_

#include "Comm_Abstract.h"

class cComm_I2C : public cComm_Driver
{
  public:
  cComm_I2C(uint8_t u8DevAddress);

  ~cComm_I2C();

  private:
  uint8_t m_u8DeviceAddress;

  inline bool i2c_start(void);

  inline bool i2c_repeat_start(void);

  unsigned char i2c_write(unsigned char byData, unsigned char byMode);

  inline void i2c_stop(void);

  public:
  bool Send(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);

  bool Receive(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
};



#endif /* COMM_I2C_H_ */
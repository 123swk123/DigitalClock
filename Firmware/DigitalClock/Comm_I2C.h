/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* Comm_I2C.h is part of Digital Clock.
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
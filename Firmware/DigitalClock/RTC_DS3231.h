/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* RTC_DS3231.h is part of Digital Clock.
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


#ifndef RTC_DS3231_H_
#define RTC_DS3231_H_

#include "RTC_Abstract.h"
#include "Comm_I2C.h"

class cRTC_Driver_DS3231 : public cRTC_Driver
{
  private:
  cComm_I2C m_objI2C;

  public:
  cRTC_Driver_DS3231();

  public:
  virtual bool Write_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
  virtual bool Read_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
  virtual uint8_t Status();
  virtual void SetClock(TIME *sTime);
  virtual void SetDate(DATE *sDate);
  virtual void GetClock(TIME *sTime);
  virtual void GetDate(DATE *sDate);
};




#endif /* RTC_DS3231_H_ */
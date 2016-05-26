/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* RTC_Abstract.h is part of Digital Clock.
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


#ifndef RTC_ABSTRACT_H_
#define RTC_ABSTRACT_H_

#include <stdint.h>
#include "Comm_Abstract.h"

#define RTC_STATUS_OK 0x00
#define RTC_STATUS_NG 0x80

typedef struct
{
  uint8_t u8Seconds;
  uint8_t u8Minutes;
  uint8_t u8Hours;
}TIME;

typedef struct
{
  uint8_t u8Day;
  uint8_t u8Date;
  uint8_t u8Month;
  uint8_t u8Year;
}DATE;

typedef struct
{
  
}RTC;

class cRTC_Driver
{
  protected:

  public:
  virtual bool Write_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size) = 0;
  virtual bool Read_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size) = 0;
  virtual uint8_t Status() = 0;

  virtual void SetClock(TIME *sTime) = 0;
  virtual void SetDate(DATE *sDate) = 0;
  virtual void GetClock(TIME *sTime) = 0;
  virtual void GetDate(DATE *sDate) = 0;
};



#endif /* RTC_ABSTRACT_H_ */
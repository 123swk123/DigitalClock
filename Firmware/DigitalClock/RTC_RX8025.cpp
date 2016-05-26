/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* RTC_RX8025.cpp is part of Digital Clock.
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

#include "RTC_RX8025.h"

#define RTC_RX8025_I2C_ADDR 0x64

#define I2C_WRITE 0x00
#define I2C_READ  0x01

#define RTC_RX8025_REG_SEC        0x00
#define RTC_RX8025_REG_ALRMW_MIN  0x80
#define RTC_RX8025_REG_CONTROL1   0xE0

#define RTC_RX8025_CTRL1_CT0    0x01
#define RTC_RX8025_CTRL1_CT1    0x02
#define RTC_RX8025_CTRL1_CT2    0x04
#define RTC_RX8025_CTRL1_TEST   0x08
#define RTC_RX8025_CTRL1_CLEN2  0x10
#define RTC_RX8025_CTRL1_12_24  0x20
#define RTC_RX8025_CTRL1_DALE   0x40
#define RTC_RX8025_CTRL1_WALE   0x80

#define RTC_RX8025_CTRL2_DAFG   0x01
#define RTC_RX8025_CTRL2_WAFG   0x02
#define RTC_RX8025_CTRL2_CTFG   0x04
#define RTC_RX8025_CTRL2_CLEN1  0x08
#define RTC_RX8025_CTRL2_PON    0x10
#define RTC_RX8025_CTRL2_XST    0x20
#define RTC_RX8025_CTRL2_VDET   0x40
#define RTC_RX8025_CTRL2_VDSL   0x80

cRTC_Driver_RX8025::cRTC_Driver_RX8025():m_objI2C(RTC_RX8025_I2C_ADDR)
{
  uint8_t u8Temp[2];
  if (Status() == RTC_STATUS_NG)
  {
    //RTC is not in known state
    
    //reset the flags for next monitoring cycle to report
    u8Temp[0] = (RTC_RX8025_CTRL1_12_24|RTC_RX8025_CTRL1_CT1|RTC_RX8025_CTRL1_CT0);
    u8Temp[1] = RTC_RX8025_CTRL2_XST;
    m_objI2C.Send(RTC_RX8025_REG_CONTROL1, u8Temp, 2);
  }
}

uint8_t cRTC_Driver_RX8025::Status()
{
  uint8_t u8Temp[2];

  m_objI2C.Receive(RTC_RX8025_REG_CONTROL1, u8Temp, 2);

  if((u8Temp[1] & RTC_RX8025_CTRL2_PON) || (!(u8Temp[1] & RTC_RX8025_CTRL2_XST)))
  {
    return RTC_STATUS_NG;
  }
  
  return RTC_STATUS_OK;
}

bool cRTC_Driver_RX8025::Write_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  m_objI2C.Send(u8Address, u8ptrData, u8Size);
  return true;
}

bool cRTC_Driver_RX8025::Read_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  m_objI2C.Receive(u8Address, u8ptrData, u8Size);
  return true;
}

void cRTC_Driver_RX8025::SetClock(TIME *sTime)
{
  Write_Mem(RTC_RX8025_REG_SEC, (uint8_t*) sTime, (uint8_t)sizeof(TIME));
}

void cRTC_Driver_RX8025::SetDate(DATE *sDate)
{
  Write_Mem(RTC_RX8025_REG_SEC + 0x03, (uint8_t*) sDate, (uint8_t)sizeof(DATE));
}

void cRTC_Driver_RX8025::GetClock(TIME *sTime)
{
  Read_Mem(RTC_RX8025_REG_SEC, (uint8_t*) sTime, (uint8_t)sizeof(TIME));
}

void cRTC_Driver_RX8025::GetDate(DATE *sDate)
{
  Read_Mem(RTC_RX8025_REG_SEC + 0x03, (uint8_t*) sDate, (uint8_t)sizeof(DATE));
}

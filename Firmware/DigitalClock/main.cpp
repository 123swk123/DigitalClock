/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* main.cpp is part of Digital Clock.
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
#include <stdio.h>
#include <string.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "Comm_I2C.h"
#include "Comm_UART.h"
#include "RTC.h"

int main(void)
{
  // Crystal Oscillator division factor: 2
  //CLKPR=(1<<CLKPCE);
  //CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (1<<CLKPS0);

  char strBuff[16];
  
  cComm_UART objUart;
  
  _delay_ms(500);

  //cRTC_Driver_DS3231 objRTC_DS3231;
  cRTC_Driver_RX8025 objRTC_RX8025;
  cRTC *objRTC;

  objRTC = (cRTC *)&objRTC_RX8025;

  TIME sTime = {0x00, 0x50, 0x15};
  //DATE sDate = {0x04, 0x25, 0x05, 0x16};
  //objRTC->SetClock(&sTime);
  //objRTC->SetDate(&sDate);

  while(1){

  _delay_ms(500);
  
  objRTC->GetClock(&sTime);
 
  uint8_t u8strLen = sprintf(strBuff, "TIME:%X:%X:%X\r\n", sTime.u8Hours, sTime.u8Minutes, sTime.u8Seconds);

  objUart.Send(0, (uint8_t*)strBuff, u8strLen);
  }
}


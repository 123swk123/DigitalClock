/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* RTC.h is part of Digital Clock.
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


#ifndef RTC_H_
#define RTC_H_

#include "RTC_DS3231.h"
#include "RTC_RX8025.h"

class cRTC : public cRTC_Driver
{
  public:
    cRTC();
    ~cRTC();
};


#endif /* RTC_H_ */
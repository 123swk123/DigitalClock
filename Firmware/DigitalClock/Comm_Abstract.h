/************************************************************************
* Copyright (C) 2016 SwK(123swk123@gmail.com)
*
* Comm_Abstract.h is part of Digital Clock.
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
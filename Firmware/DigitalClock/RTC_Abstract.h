/*
 * RTC_Abstract.h
 *
 * Created: 25-05-2016 02:33:03
 *  Author: karthikeyan
 */ 


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
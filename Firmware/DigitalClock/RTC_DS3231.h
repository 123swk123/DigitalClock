/*
 * RTC_DS3231.h
 *
 * Created: 25-05-2016 02:35:10
 *  Author: karthikeyan
 */ 


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
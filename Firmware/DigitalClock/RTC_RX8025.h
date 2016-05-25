/*
 * RTC_RX8025.h
 *
 * Created: 26-05-2016 01:23:51
 *  Author: karthikeyan
 */ 


#ifndef RTC_RX8025_H_
#define RTC_RX8025_H_

#include "RTC_Abstract.h"
#include "Comm_I2C.h"

class cRTC_Driver_RX8025 : public cRTC_Driver
{
  private:
  cComm_I2C m_objI2C;

  public:
  cRTC_Driver_RX8025();

  public:
  virtual bool Write_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
  virtual bool Read_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size);
  virtual uint8_t Status();
  virtual void SetClock(TIME *sTime);
  virtual void SetDate(DATE *sDate);
  virtual void GetClock(TIME *sTime);
  virtual void GetDate(DATE *sDate);
};


#endif /* RTC_RX8025_H_ */
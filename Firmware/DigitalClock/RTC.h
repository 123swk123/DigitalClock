/*
 * RTC.h
 *
 * Created: 25-05-2016 02:34:23
 *  Author: karthikeyan
 */ 


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
/*
 * RTC_DS3231.cpp
 *
 * Created: 25-05-2016 02:35:21
 *  Author: karthikeyan
 */ 
#include "RTC_DS3231.h"

#define REG_SEC 0x00
#define REG_MIN 0x01
#define REG_HOUR 0x02
#define REG_DAY 0x03
#define REG_DATE 0x04
#define REG_MONTH 0x05
#define REG_YEAR 0x06
#define REG_ALM_1_SEC 0x07
#define REG_ALM_1_MIN 0x08
#define REG_ALM_1_HOUR 0x09
#define REG_ALM_1_DAY_R_DATE 0x0A
#define REG_ALM_2_MIN 0x0B
#define REG_ALM_2_HOUR 0x0C
#define REG_ALM_2_DAY_R_DATE 0x0D
#define REG_CTRL 0x0E
#define REG_STATUS 0x0F
#define REG_AGING_OFFSET 0x10
#define REG_TEMP_MSB 0x11
#define REG_TEMP_LSB 0x12

#define CTRL_A1IE 0
#define CTRL_A2IE 1
#define CTRL_INTCN 2
#define CTRL_RS1 3
#define CTRL_RS2 4
#define CTRL_CONV 5
#define CTRL_BBSQW 6
#define CTRL_n_EOSC 7

#define STATUS_A1IF 0
#define STATUS_A2IF 1
#define STATUS_BSY 2
#define STATUS_EN32kHz 3
#define STATUS_OSF 7

cRTC_Driver_DS3231::cRTC_Driver_DS3231():m_objI2C(0xD0)
{
  //CTRL REG
  //Enable Oscillator
  //Disable Battery Backup SQW
  //Enable SQ Wave output @ 1Hz
  //Disable All alarms interrupts

  //STATUS REG
  /*Clear OSF, EN32kHz, BSY, A2F, A1F*/
  uint8_t u8Data[2] = {/*CTRL*/0, /*STATUS*/0};

  m_objI2C.Send(REG_CTRL, u8Data, 2);
}

bool cRTC_Driver_DS3231::Write_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  m_objI2C.Send(u8Address, u8ptrData, u8Size);
  return true;
}

bool cRTC_Driver_DS3231::Read_Mem(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  m_objI2C.Receive(u8Address, u8ptrData, u8Size);
  return true;
}

uint8_t cRTC_Driver_DS3231::Status()
{
  uint8_t u8Temp;

  /*Clear OSF, EN32kHz, BSY, A2F, A1F*/
  uint8_t u8Data = 0; 

  m_objI2C.Receive(REG_STATUS, &u8Temp, 1);

  m_objI2C.Send(REG_STATUS, &u8Data, 1);
  if (u8Temp & (1<<STATUS_OSF))
  {
    return RTC_STATUS_NG;
  }
  
  return RTC_STATUS_OK;
}

void cRTC_Driver_DS3231::SetClock(TIME *sTime)
{
  m_objI2C.Send(REG_SEC, (uint8_t*)sTime, (uint8_t)sizeof(TIME));
}

void cRTC_Driver_DS3231::SetDate(DATE *sDate)
{
  m_objI2C.Send(REG_DAY, (uint8_t*)sDate, (uint8_t)sizeof(DATE));
}

void cRTC_Driver_DS3231::GetClock(TIME *sTime)
{
  m_objI2C.Receive(REG_SEC, (uint8_t*)sTime, (uint8_t)sizeof(TIME));
}

void cRTC_Driver_DS3231::GetDate(DATE *sDate)
{
  m_objI2C.Receive(REG_DAY, (uint8_t*)sDate, (uint8_t)sizeof(DATE));
}

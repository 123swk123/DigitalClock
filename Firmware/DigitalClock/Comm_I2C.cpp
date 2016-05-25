/*
 * Comm_I2C.cpp
 *
 * Created: 25-05-2016 02:03:47
 *  Author: karthikeyan
 */ 
#include <avr/io.h>
#include "Comm_Abstract.h"
#include "Comm_I2C.h"

#define I2C_HARDWARE

#define I2C_STATUS_CODE_START_CONDITION 0x8
#define I2C_STATUS_CODE_REPEAT_START_CONDITION 0x10
#define I2C_STATUS_CODE_SLA_W_TXD_ACK_RXD 0x18
#define I2C_STATUS_CODE_SLA_W_TXD_NOACK_RXD 0x20
#define I2C_STATUS_CODE_DATA_TXD_ACK_RXD 0x28
#define I2C_STATUS_CODE_DATA_TXD_NOACK_RXD 0x30
#define I2C_STATUS_CODE_ERROR_SLAW_DATA_TXD 0x38

#define I2C_STATUS_CODE_ERROR_SLAR_DATA_RXD 0x38
#define I2C_STATUS_CODE_SLA_R_TXD_ACK_RXD 0x40
#define I2C_STATUS_CODE_SLA_R_TXD_NOACK_RXD 0x48
#define I2C_STATUS_CODE_DATA_RXD_ACK_TXD 0x50
#define I2C_STATUS_CODE_DATA_RXD_NOACK_TXD 0x58

cComm_I2C::cComm_I2C(uint8_t u8DevAddress) : m_u8DeviceAddress(u8DevAddress)
{
  // 2 Wire Bus initialization
  // Generate Acknowledge Pulse: On
  // 2 Wire Bus Slave Address: 0h
  // General Call Recognition: Off
  // Bit Rate: 100.000 kHz
  TWSR=0x00;
  TWBR=0x20;
  TWAR=0x00;
  TWCR=0x44;
}

cComm_I2C::~cComm_I2C()
{

}

inline bool cComm_I2C::i2c_start(void)
{
  #ifdef I2C_HARDWARE
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  while (!(TWCR & (1<<TWINT)));
  if ((TWSR & 0xF8) != I2C_STATUS_CODE_START_CONDITION)
  return false;
  else
  return true;
  #endif
}

inline bool cComm_I2C::i2c_repeat_start(void)
{
  #ifdef I2C_HARDWARE
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
  while (!(TWCR & (1<<TWINT)));
  if ((TWSR & 0xF8) != I2C_STATUS_CODE_REPEAT_START_CONDITION)
  return false;
  else
  return true;
  #endif
}

unsigned char cComm_I2C::i2c_write(unsigned char byData, unsigned char byMode)
{
  #ifdef I2C_HARDWARE
  if(byMode == I2C_STATUS_CODE_DATA_RXD_ACK_TXD)
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
  else if(byMode == I2C_STATUS_CODE_DATA_RXD_NOACK_TXD)
  TWCR = (1<<TWINT) | (1<<TWEN);
  else
  {
    TWDR = byData;
    TWCR = (1<<TWINT) | (1<<TWEN);
  }

  while (!(TWCR & (1<<TWINT)));
  
  if ((byMode == I2C_STATUS_CODE_DATA_RXD_ACK_TXD) && ((TWSR & 0xF8) == byMode))
  return TWDR;
  else if((byMode == I2C_STATUS_CODE_DATA_RXD_NOACK_TXD) && ((TWSR & 0xF8) == byMode))
  return TWDR;
  else if((TWSR & 0xF8) != byMode)
  return false;
  else
  return true;
  #endif
}

inline void cComm_I2C::i2c_stop(void)
{
  #ifdef I2C_HARDWARE
  while (!(TWCR & (1<<TWINT)));
  TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
  #endif
}

bool cComm_I2C::Send(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  i2c_start();
  i2c_write(m_u8DeviceAddress, I2C_STATUS_CODE_SLA_W_TXD_ACK_RXD);
  i2c_write(u8Address, I2C_STATUS_CODE_DATA_TXD_ACK_RXD);

  while (u8Size--)
  {
    i2c_write(*u8ptrData++, I2C_STATUS_CODE_DATA_TXD_ACK_RXD);
  }
  i2c_stop();
  return true;
}

bool cComm_I2C::Receive(uint8_t u8Address, uint8_t *u8ptrData, uint8_t u8Size)
{
  i2c_start();
  i2c_write(m_u8DeviceAddress, I2C_STATUS_CODE_SLA_W_TXD_ACK_RXD);
  i2c_write(u8Address, I2C_STATUS_CODE_DATA_TXD_ACK_RXD);
  i2c_repeat_start();
  i2c_write(m_u8DeviceAddress|0x01, I2C_STATUS_CODE_SLA_R_TXD_ACK_RXD);
  u8Size--;
  while (u8Size--)
  {
    *u8ptrData++ = i2c_write(0xFF, I2C_STATUS_CODE_DATA_RXD_ACK_TXD);
  }
  *u8ptrData++ = i2c_write(0xFF, I2C_STATUS_CODE_DATA_RXD_NOACK_TXD);
  i2c_stop();
  return true;
}



#ifndef __DS1302_H
#define __DS1302_H
										  	  
#include "stm32f10x.h"

#define DSIO_H   GPIO_SetBits(GPIOA,GPIO_Pin_4)
#define DSIO_L   GPIO_ResetBits(GPIOA,GPIO_Pin_4)
#define RST_H    GPIO_SetBits(GPIOA,GPIO_Pin_3)
#define RST_L    GPIO_ResetBits(GPIOA,GPIO_Pin_3)
#define SCLK_H   GPIO_SetBits(GPIOA,GPIO_Pin_2)
#define SCLK_L   GPIO_ResetBits(GPIOA,GPIO_Pin_2)
#define GET_DSIO  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)

//---����ȫ�ֺ���---//
void Ds1302Write(uint8_t addr, uint8_t dat);
uint8_t Ds1302Read(uint8_t addr);
void Ds1302Init(void);
void Ds1302ReadTime(void);

//---����ȫ�ֱ���--//
extern uint8_t TIME[7];	//����ȫ�ֱ���

#endif







































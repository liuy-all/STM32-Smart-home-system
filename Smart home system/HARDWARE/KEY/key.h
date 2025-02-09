#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
 	 
#define KEY0    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)//读取按键0
#define KEY1    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)//读取按键1
#define KEY2    GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//读取按键2 
#define WK_UP   GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(WK_UP) 

 

#define KEY0_PRES 	2	//KEY0按下
#define KEY1_PRES	3	//KEY1按下
#define KEY2_PRES	4	//KEY2按下
#define WKUP_PRES   1	//KEY_UP按下(即WK_UP/KEY_UP)


void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数					    
#endif

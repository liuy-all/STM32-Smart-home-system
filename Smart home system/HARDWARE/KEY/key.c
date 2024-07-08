#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
							    
//按键初始化函数
void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB,ENABLE);//使能PORTA,PORTE时钟

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_5|GPIO_Pin_8|GPIO_Pin_9;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIOE2,3,4

	//初始化 WK_UP-->GPIOA.0	  下拉输入
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入  //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0设置成输入，默认下拉	  
	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOA.0

}

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0||GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0||GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0||GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==0)return KEY0_PRES;
		else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==0)return KEY1_PRES;
		else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==0)return KEY2_PRES;
		else if(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==0)return WKUP_PRES;
	}else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5)==1&&GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)==1&&GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)==1&&GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)==1)key_up=1; 	    
 	return 0;// 无按键按下
}

#ifndef  __ADC_H
#define  __ADC_H

#include "sys.h"

//uint8_t channel[4]={0x01,0x02,0x03,0x05};
//u16 ADC_Value[4];

void Adc1_Channe_Init(void);
u16 get_Adc_Value(u8 ch);
void ADC_Channel_Value(u8 *p,u16 *q);
//u16 get_Adc_Value2(u8 ch);
//u16 get_Adc_Value3(u8 ch);
//u16 get_Adc_Value4(u8 ch);
//u16 T_get_Adc_Value(u8 ch);
float V_get_alue(u16 J_value);

#endif

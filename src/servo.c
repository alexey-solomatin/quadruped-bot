//
// This file is part of the Quadruped Bot firmware.
// Copyright (c) 2016 Alexey Solomatin.
//

#include "servo.h"

/*#############################################################
 Driver name	    : servo_f3.c
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Provides a library to control the position
 of up to 12 servos.

 Requirements    : * STM32F3-Discovery Board

 Functions				: SERVO1_Init_on_PA5(), SERVO1_Init_on_PA15()
 SERVO2_Init_on_PA1(),	SERVO2_Init_on_PB3()
 SERVO3_Init_on_PA2(),	SERVO3_Init_on_PB10()
 SERVO4_Init_on_PA3(),	SERVO4_Init_on_PB11()
 SERVO5_Init_on_PA6(),	SERVO5_Init_on_PB4(), SERVO5_Init_on_PC6()
 SERVO6_Init_on_PA4(),	SERVO6_Init_on_PA7(), SERVO6_Init_on_PB5(), SERVO6_Init_on_PC7(), SERVO6_Init_on_PE3()
 SERVO7_Init_on_PB0(),	SERVO7_Init_on_PC8()
 SERVO8_Init_on_PB1(),	SERVO8_Init_on_PC9()
 SERVO9_Init_on_PB6(),	SERVO9_Init_on_PD12()
 SERVO10_Init_on_PB7(),	SERVO10_Init_on_PD13()
 SERVO11_Init_on_PB8(),	SERVO11_Init_on_PD14()
 SERVO12_Init_on_PD15(),	SERVO12_Init_on_PF6(), SERVO12_Init_on_PB9()

 SERVO1_SetPulse()
 SERVO2_SetPulse()
 SERVO3_SetPulse()
 SERVO4_SetPulse()
 SERVO5_SetPulse()
 SERVO6_SetPulse()
 SERVO7_SetPulse()
 SERVO8_SetPulse()
 SERVO9_SetPulse()
 SERVO10_SetPulse()
 SERVO11_SetPulse()
 SERVO12_SetPulse()

 Special Note(s) : NONE
 ##############################################################*/

/***************************************************************
 Function name   : SERVO1_Init_on_PA5
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO1 output on PA5.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO1_Init_on_PA5(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//configure PA0 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO1_Init_on_PA15
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO1 output on PA15.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO1_Init_on_PA15(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//configure PA15 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource15, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO2_Init_on_PA1
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO2 output on PA1.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO2_Init_on_PA1(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//configure PA1 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource1, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO2_Init_on_PB3
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO2 output on PB3.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO2_Init_on_PB3(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//configure PB3 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource3, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO3_Init_on_PA2
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO3 output on PA2.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO3_Init_on_PA2(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;//configure PA2 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare3(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO3_Init_on_PB10
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO3 output on PB10.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO3_Init_on_PB10(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//configure PB10 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare3(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO4_Init_on_PA3
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO4 output on PA3.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO4_Init_on_PA3(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//configure PA3 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO4_Init_on_PB11
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO4 output on PB11.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO4_Init_on_PB11(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);//enable the TIM2 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;//configure PB11 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_1);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM2 (GPIO_AF_1)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM2, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM2, ENABLE);										//enable TIM2
}

/***************************************************************
 Function name   : SERVO5_Init_on_PA6
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO5 output on PA6.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO5_Init_on_PA6(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//configure PA6 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO5_Init_on_PA6
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO5 output on PA6.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO5_Init_on_PB4(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//configure PB4 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO5_Init_on_PC6
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO5 output on PC6.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO5_Init_on_PC6(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	//enable the AHB Peripheral Clock to use GPIOC
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//configure PC6 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO6_Init_on_PA4
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO6 output on PA4.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO6_Init_on_PA4(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;//configure PA4 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource4, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO6_Init_on_PA7
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO6 output on PA7.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO6_Init_on_PA7(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);	//enable the AHB Peripheral Clock to use GPIOA
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//configure PA7 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO6_Init_on_PB5
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO6 output on PB5.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO6_Init_on_PB5(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//configure PB5 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO6_Init_on_PC7
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO6 output on PC7.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO6_Init_on_PC7(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	//enable the AHB Peripheral Clock to use GPIOC
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//configure PC7 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO6_Init_on_PE3
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO6 output on PE3.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO6_Init_on_PE3(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);	//enable the AHB Peripheral Clock to use GPIOE
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//configure PE3 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOE, GPIO_PinSource3, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO7_Init_on_PB0
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO7 output on PB0.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO7_Init_on_PB0(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//configure PB0 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource0, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare3(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO7_Init_on_PC8
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO7 output on PC8.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO7_Init_on_PC8(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	//enable the AHB Peripheral Clock to use GPIOC
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//configure PC8 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare3(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO8_Init_on_PB1
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO8 output on PB1.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO8_Init_on_PB1(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;//configure PB1 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource1, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO8_Init_on_PC9
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO8 output on PC9.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO8_Init_on_PC9(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);	//enable the AHB Peripheral Clock to use GPIOC
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);//enable the TIM3 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//configure PC9 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource9, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM3, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM3, ENABLE);										//enable TIM3
}

/***************************************************************
 Function name   : SERVO9_Init_on_PB6
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO9 output on PB6.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO9_Init_on_PB6(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//configure PB6 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO9_Init_on_PD12
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO9 output on PD12.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO9_Init_on_PD12(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);	//enable the AHB Peripheral Clock to use GPIOD
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;//configure PD12 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare1(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO10_Init_on_PB7
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO10 output on PB7.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO10_Init_on_PB7(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;//configure PB7 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO10_Init_on_PD13
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO10 output on PD13.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO10_Init_on_PD13(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);	//enable the AHB Peripheral Clock to use GPIOD
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;//configure PD13 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare2(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO11_Init_on_PB8
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO11 output on PB8.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO11_Init_on_PB8(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;//configure PB8 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource8, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare3(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO11_Init_on_PD14
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO11 output on PD14.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO11_Init_on_PD14(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);	//enable the AHB Peripheral Clock to use GPIOD
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;//configure PD14 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare3(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO12_Init_on_PD15
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO12 output on PD15.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO12_Init_on_PD15(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOD, ENABLE);	//enable the AHB Peripheral Clock to use GPIOD
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//configure PD15 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO12_Init_on_PF6
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO12 output on PF6.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO12_Init_on_PF6(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOF, ENABLE);	//enable the AHB Peripheral Clock to use GPIOF
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;//configure PF6 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOF, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOF, GPIO_PinSource6, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}

/***************************************************************
 Function name   : SERVO12_Init_on_PB9
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Initializes the SERVO12 output on PB9.  The
 startup position will be set to 1500us.

 Special Note(s) : * This function should only be called once,
 otherwise it could cause eradic movement of
 the servo

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
void SERVO12_Init_on_PB9(void) {
	GPIO_InitTypeDef GPIO_InitStructure;			//structure for GPIO setup
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;//structure for TIM Time Base
	TIM_OCInitTypeDef TIM_OCInitStructure;	//structure for TIM Output Compare

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);	//enable the AHB Peripheral Clock to use GPIOB
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);//enable the TIM4 clock

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;//configure PB9 in alternate function pushpull mode
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_2);//connect the pin to the desired peripherals' Alternate Function (AF) - TIM3 (GPIO_AF_2)

	TIM_TimeBaseStructure.TIM_Prescaler = 71;//configure timer to create 50Hz signal
	TIM_TimeBaseStructure.TIM_Period = 20000;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;	//PWM mode configuration
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);

	TIM_SetCompare4(TIM4, 1500);	//set the default compare value to 1500us
	TIM_Cmd(TIM4, ENABLE);										//enable TIM4
}


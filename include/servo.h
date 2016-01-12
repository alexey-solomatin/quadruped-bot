//
// This file is part of the Quadruped Bot firmware.
// Copyright (c) 2016 Alexey Solomatin.
//

#ifndef SERVO_H_
#define SERVO_H_

#include "stm32f30x.h"

// ---- Servo driver definitions ----------------------------------------------

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
extern void SERVO1_Init_on_PA5(void);

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
extern void SERVO1_Init_on_PA15(void);

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
extern void SERVO2_Init_on_PA1(void);

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
extern void SERVO2_Init_on_PB3(void);

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
extern void SERVO3_Init_on_PA2(void);

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
extern void SERVO3_Init_on_PB10(void);

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
extern void SERVO4_Init_on_PA3(void);

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
extern void SERVO4_Init_on_PB11(void);

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
extern void SERVO5_Init_on_PA6(void);

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
extern void SERVO5_Init_on_PB4(void);

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
extern void SERVO5_Init_on_PC6(void);

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
extern void SERVO6_Init_on_PA4(void);

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
extern void SERVO6_Init_on_PA7(void);

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
extern void SERVO6_Init_on_PB5(void);

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
extern void SERVO6_Init_on_PC7(void);

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
extern void SERVO6_Init_on_PE3(void);

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
extern void SERVO7_Init_on_PB0(void);

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
extern void SERVO7_Init_on_PC8(void);

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
extern void SERVO8_Init_on_PB1(void);

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
extern void SERVO8_Init_on_PC9(void);

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
extern void SERVO9_Init_on_PB6(void);

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
extern void SERVO9_Init_on_PD12(void);

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
extern void SERVO10_Init_on_PB7(void);

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
extern void SERVO10_Init_on_PD13(void);

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
extern void SERVO11_Init_on_PB8(void);

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
extern void SERVO11_Init_on_PD14(void);

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
extern void SERVO12_Init_on_PD15(void);

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
extern void SERVO12_Init_on_PF6(void);

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
extern void SERVO12_Init_on_PB9(void);

/***************************************************************
 Function name   : SERVO1_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO1_SetPulse(unsigned int width) {
	TIM_SetCompare1(TIM2, width);
}

/***************************************************************
 Function name   : SERVO2_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO2_SetPulse(unsigned int width) {
	TIM_SetCompare2(TIM2, width);
}

/***************************************************************
 Function name   : SERVO3_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO3_SetPulse(unsigned int width) {
	TIM_SetCompare3(TIM2, width);
}

/***************************************************************
 Function name   : SERVO4_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO4_SetPulse(unsigned int width) {
	TIM_SetCompare4(TIM2, width);
}

/***************************************************************
 Function name   : SERVO5_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO5_SetPulse(unsigned int width) {
	TIM_SetCompare1(TIM3, width);
}

/***************************************************************
 Function name   : SERVO6_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO6_SetPulse(unsigned int width) {
	TIM_SetCompare2(TIM3, width);
}

/***************************************************************
 Function name   : SERVO7_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO7_SetPulse(unsigned int width) {
	TIM_SetCompare3(TIM3, width);
}

/***************************************************************
 Function name   : SERVO8_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO8_SetPulse(unsigned int width) {
	TIM_SetCompare4(TIM3, width);
}

/***************************************************************
 Function name   : SERVO9_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO9_SetPulse(unsigned int width) {
	TIM_SetCompare1(TIM4, width);
}

/***************************************************************
 Function name   : SERVO10_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO10_SetPulse(
		unsigned int width) {
	TIM_SetCompare2(TIM4, width);
}

/***************************************************************
 Function name   : SERVO11_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO11_SetPulse(
		unsigned int width) {
	TIM_SetCompare3(TIM4, width);
}

/***************************************************************
 Function name   : SERVO12_SetPulse
 Author 					: Grant Phillips
 Date Modified   : 17/08/2013
 Compiler        : Keil ARM-MDK (uVision V4.70.0.0)
 Tested On       : STM32F3-Discovery

 Description			: Sets the HIGH pulse width for a specific
 servo output.

 Special Note(s) : * Be carefull when using values less than 1000
 and more than 2000.  This could push the servo
 past its hardware limits.
 * The value 1500 (1.5ms) is normally midpoint

 Parameters			: width		-	the HIGH pulse width in us
 Return value		: NONE
 ***************************************************************/
inline void __attribute__((always_inline)) SERVO12_SetPulse(
		unsigned int width) {
	TIM_SetCompare4(TIM4, width);
}

#endif /* SERVO_H_ */

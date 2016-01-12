/**
  ******************************************************************************
  * @file    usb_endp.c
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    21-January-2013
  * @brief   Endpoint routines
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


/* Includes ------------------------------------------------------------------*/
#include "usb_lib.h"
#include "usb_desc.h"
#include "usb_mem.h"
#include "hw_config.h"
#include "usb_istr.h"
#include "usb_pwr.h"
#include "servo.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Interval between sending IN packets in frame number (1 frame = 1ms) */
#define VCOMPORT_IN_FRAME_INTERVAL             5

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t USB_Rx_Buffer[VIRTUAL_COM_PORT_DATA_SIZE];
extern  uint8_t USART_Rx_Buffer[];
extern uint32_t USART_Rx_ptr_out;
extern uint32_t USART_Rx_length;
extern uint8_t  USB_Tx_State;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/*******************************************************************************
* Function Name  : EP1_IN_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP1_IN_Callback (void)
{  
}

/*******************************************************************************
* Function Name  : EP3_OUT_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void EP3_OUT_Callback(void)
{
  uint16_t USB_Rx_Cnt;
  
  /* Get the received data buffer and update the counter */
  USB_Rx_Cnt = USB_SIL_Read(EP3_OUT, USB_Rx_Buffer);
  //uint16_t servo_pulse = (uint16_t)USB_Rx_Buffer[1] + (uint16_t)USB_Rx_Buffer[0];
  uint16_t servo_pulse = USB_Rx_Buffer[1];
  servo_pulse <<= 8;
  servo_pulse += USB_Rx_Buffer[0];
  
  /* USB data will be immediately processed, this allow next USB traffic being 
  NAKed till the end of the USART Xfer */
    /**/
  /*
    switch(servo_pulse)
	{
		case 250:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0100);
			break;
		
		case 251:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0300);
			break;
		
		case 253:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0700);
			break;
		
		case 254:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0F00);
			break;
		
		case 255:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x1F00);
			break;
	
		case 256:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x3F00);
			break;

		case 257:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x7F00);
			break;
		
		case 1000:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0xFF00);
			break;
	}*/
    SERVO5_SetPulse(servo_pulse);
    /**/
    /*
	switch(USB_Rx_Buffer[1])
	{
		case 0x01:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0100);
			break;
		
		case 0x02:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0300);
			break;
		
		case 0x03:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0700);
			break;
		
		case 0x04:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x0F00);
			break;
		
		case 0x05:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x1F00);
			break;
		
		case 0x06:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x3F00);
			break;
		
		case 0x07:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0x7F00);
			break;
		
		case 0x08:
			GPIO_ResetLeds();		
			GPIO_Write(GPIOE, 0xFF00);
			break;
	}
    */
 
  /* Enable the receive of data on EP3 */
  SetEPRxValid(ENDP3);
}


/*******************************************************************************
* Function Name  : SOF_Callback / INTR_SOFINTR_Callback
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
void SOF_Callback(void)
{
  static uint32_t FrameCount = 0;
  
  if(bDeviceState == CONFIGURED)
  {
    if (FrameCount++ == VCOMPORT_IN_FRAME_INTERVAL)
    {
      /* Reset the frame counter */
      FrameCount = 0;
      
      /* Check the data to be sent through IN pipe */
      Handle_USBAsynchXfer();
    }
  }  
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


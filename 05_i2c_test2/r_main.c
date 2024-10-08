/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2011, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_main.c
* Version      : CodeGenerator for RL78/G12 V2.04.07.02 [17 Nov 2023]
* Device(s)    : R5F1026A
* Tool-Chain   : CCRL
* Description  : This file implements main function.
* Creation Date: 2024/9/10
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_serial.h"
#include "r_cg_wdt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern uint8_t rx_end;
extern uint8_t tx_end;
uint8_t g_read_value[250];  // buffer I2C read
//uint8_t g_write_value[250]; // buffer I2C write
volatile uint8_t g_iica0_tx_buf[4] = { 0xAA, 0xBB, 0xCC, 0xDD };
/* End user code. Do not edit comment generated here */
void R_MAIN_UserInit(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
	tx_end = 0;
	rx_end = 0;
    R_MAIN_UserInit();	
    /* Start user code. Do not edit comment generated here */
	R_IICA0_Slave_Receive(&g_read_value[0],1);
	//g_write_value[0] = 0x55;
	//R_IICA0_Slave_Send(&g_write_value[0],1);
	R_IICA0_Slave_Send((uint8_t)g_iica0_tx_buf, 4U);
    while (1U)
    {
#if 1
        if (rx_end == 1) // 1 byte IIC data recieved?
		{
			rx_end = 0; //clr recieve flag
			//set recieve another IIC data
			R_IICA0_Slave_Receive(&g_read_value[0],1);
		}
		if (tx_end == 1) // 1 byte IIC data transmit?
		{
			tx_end = 0;
			//g_write_value[0] = 0x55;
			R_IICA0_Slave_Send((uint8_t)g_iica0_tx_buf, 4U);
		}
#endif
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_MAIN_UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_MAIN_UserInit(void)
{
    /* Start user code. Do not edit comment generated here */
    EI();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/******************************************************************//**
* @file		lpc_system_init.c
* @brief	Contains all functions support for SYSTEM INIT library
* 			on LPC17xx
* @version	1.0
* @date		24. July. 2013
* @author	Dwijay.Edutech Learning Solutions
**********************************************************************/

/* Peripheral group ----------------------------------------------------------- */
/** @addtogroup SYSTEM_INIT
 * @{
 */

/* Includes ------------------------------------------------------------------- */
#include "lpc_system_init.h"

/* If this source file built with example, the LPC17xx FW library configuration
 * file in each example directory ("lpc17xx_libcfg.h") must be included,
 * otherwise the default FW library configuration file must be included instead
 */

/** @addtogroup SYSTEM_INIT_Public_Functions
 * @{
 */

/* Public Functions ----------------------------------------------------------- */
/*********************************************************************//**
 * @brief	Initial System Init using Port and Peripheral
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void System_Init(void)
{

	LPC_WDT->WDMOD &= ~WDT_WDMOD_WDEN;  // Disable Watchdog
	SystemInit();						// Initialize system and update core clock
	Port_Init();                        // Port Initialization
	SYSTICK_Config();                   // Systick Initialization
	UART_Config(LPC_UART0, 9600);      // Uart0 Initialization
	UART_Config(LPC_UART2, 115200);     // Uart2 Initialization
	led_delay = 1000;                   // Heart Beat rate of 1Sec toggle
}

/*********************************************************************//**
 * @brief 		General Port Initialization
 * @param[in]	None
 * @return 		None
 **********************************************************************/
void Port_Init(void)
{
	GPIO_SetDir(3, _BIT(25), 1);      // Set P3.25 to Output
	GPIO_SetDir(1, _SBF(18,0xFF), 1); //Set P1.18 to P1.25 as output
	GPIO_SetValue(1,_SBF(18,0xFF));   //Clear P1.18 to P1.25
}

/**
 * @}
 */

/* End of Public Functions ---------------------------------------------------- */

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */


/*
 * uart_driver.c
 *
 *  Created on: Dec 21, 2017
 *      Author: a0225962
 */
// Driverlib includes
#include "rom.h"
#include "rom_map.h"
#include "hw_memmap.h"
#include "hw_common_reg.h"
#include "hw_types.h"
#include "hw_ints.h"
#include "uart.h"
#include "interrupt.h"
#include "pinmux.h"
#include "utils.h"
#include "prcm.h"
#include "uart_driver.h"

void InitUARTModules()
{
    MAP_UARTConfigSetExpClk(
            UARTA0_BASE,
            MAP_PRCMPeripheralClockGet(PRCM_UARTA0),
            9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
            UART_CONFIG_PAR_NONE));
    MAP_UARTConfigSetExpClk(
            UARTA1_BASE,
            MAP_PRCMPeripheralClockGet(PRCM_UARTA0),
            9600, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
            UART_CONFIG_PAR_NONE));
}

void UART_WriteString(unsigned long ulBase, unsigned char * message)
{
    while(*message)
    {
        MAP_UARTCharPut(ulBase, *message);
        message++;
    }
}

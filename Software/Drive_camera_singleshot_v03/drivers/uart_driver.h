/*
 * uart_driver.h
 *
 *  Created on: Dec 21, 2017
 *      Author: a0225962
 */

#ifndef DRIVERS_UART_DRIVER_H_
#define DRIVERS_UART_DRIVER_H_

void InitUARTModules();
void UART_WriteString(unsigned long ulBase, unsigned char * message);

#endif /* DRIVERS_UART_DRIVER_H_ */

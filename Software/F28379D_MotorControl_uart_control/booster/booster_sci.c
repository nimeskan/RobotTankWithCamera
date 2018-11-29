/*
 * booster_sci.c
 *
 *  Created on: Nov 2, 2018
 *      Author: a0225962
 */

#include "F28x_Project.h"
#include "driverlib.h"
#include "device.h"
#include "booster_sci.h"

uint16_t NewCommandAvailable = 0;
uint16_t CommandReceivedData[MAX_SCI_CHARS] = {0};

__interrupt void scibRxISR(void);


void booster_sci_init()
{

    //
    // Map the ISR to the wake interrupt.
    //
    Interrupt_register(INT_SCIB_RX, scibRxISR);

    //
    // Initialize SCIB and its FIFO.
    //
    SCI_performSoftwareReset(SCIB_BASE);

    //
    // Configure SCIB for echoback.
    //
    SCI_setConfig(SCIB_BASE, 50000000, 9600, (SCI_CONFIG_WLEN_8 |
                                             SCI_CONFIG_STOP_ONE |
                                             SCI_CONFIG_PAR_NONE));
    SCI_resetChannels(SCIB_BASE);
    SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_TXFF | SCI_INT_RXFF);
    SCI_enableFIFO(SCIB_BASE);
    SCI_enableModule(SCIB_BASE);
    SCI_performSoftwareReset(SCIB_BASE);

    //
    // Set the transmit FIFO level to 0 and the receive FIFO level to 6.
    // Enable the TXFF and RXFF interrupts.
    //
    SCI_setFIFOInterruptLevel(SCIB_BASE, SCI_FIFO_TX0, SCI_FIFO_RX6);
    SCI_enableInterrupt(SCIB_BASE, SCI_INT_RXFF);

    //
    // Clear the SCI interrupts before enabling them.
    //
    SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_TXFF | SCI_INT_RXFF);

    //
    // Enable the interrupts in the PIE: Group 9 interrupts 1 & 2.
    //
    Interrupt_enable(INT_SCIB_RX);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

}


//
// SCIBRxISR - Read two characters from the RXBUF and echo them back.
//
__interrupt void
scibRxISR(void)
{

    CommandReceivedData[0] = SCI_readCharBlockingFIFO(SCIB_BASE);
    CommandReceivedData[1] = SCI_readCharBlockingFIFO(SCIB_BASE);
    CommandReceivedData[2] = SCI_readCharBlockingFIFO(SCIB_BASE);
    CommandReceivedData[3] = SCI_readCharBlockingFIFO(SCIB_BASE);
    CommandReceivedData[4] = SCI_readCharBlockingFIFO(SCIB_BASE);
    CommandReceivedData[5] = SCI_readCharBlockingFIFO(SCIB_BASE);

    //
    // Clear the SCI RXFF interrupt and acknowledge the PIE interrupt.
    //
    SCI_clearInterruptStatus(SCIB_BASE, SCI_INT_RXFF);
    Interrupt_clearACKGroup(INTERRUPT_ACK_GROUP9);

    NewCommandAvailable = 1;
}

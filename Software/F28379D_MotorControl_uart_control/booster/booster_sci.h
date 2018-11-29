/*
 * booster_sci.h
 *
 *  Created on: Nov 2, 2018
 *      Author: a0225962
 */

#ifndef BOOSTER_BOOSTER_SCI_H_
#define BOOSTER_BOOSTER_SCI_H_

#define MAX_SCI_CHARS   16

extern uint16_t NewCommandAvailable;
extern uint16_t CommandReceivedData[MAX_SCI_CHARS];

void booster_sci_init();




#endif /* BOOSTER_BOOSTER_SCI_H_ */

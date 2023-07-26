/*
 * PrSensor.h
 *
 *  Created on: Jul 25, 2023
 *      Author: AmrAli
 */

#ifndef PRSENSOR_H_
#define PRSENSOR_H_

// libs includes

#include "state.h"

// define the states
enum{
	PrS_Reading
}PrS_state_id;

// declare state functions for pressure sensor
STATE_define(PrS_Reading);

// State pointer to function
extern void (*PrS_state)();

// APIs
void PrSensor_init();


#endif /* PRSENSOR_H_ */

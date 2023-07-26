/*
 * main_algorithem.h
 *
 *  Created on: Jul 25, 2023
 *      Author: AmrAli
 */

#ifndef ALGO_H_
#define ALGO_H_

// includes
#include "state.h"


enum{
	HighPreDetected
}alg_state_id;

// state Pointer to function
extern void (*alg_state)();

//declare state function for main algorithem
STATE_define(HighPreDetected);

#endif /* ALGO_H_ */

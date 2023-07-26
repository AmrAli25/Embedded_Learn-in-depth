/*
 * alarm_actuator.h
 *
 *  Created on: Jul 26, 2023
 *      Author: AmrAli
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"

enum{
	LedOff,
	LedOn,
	Waiting
}Led_state_id;

// state pointer to function
extern void (*Led_state)();

// state function for alarm monitor
STATE_define(LedOn);
STATE_define(LedOff);
STATE_define(Waiting);

// APIs
void Alarm_init();

#endif /* ALARM_ACTUATOR_H_ */

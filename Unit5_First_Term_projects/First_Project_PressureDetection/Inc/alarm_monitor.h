/*
 * alarm_monitor.h
 *
 *  Created on: Jul 26, 2023
 *      Author: AmrAli
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

enum{
	AlarmOff,
	AlarmOn
}AM_state_id;

// state pointer to function
extern void (*AM_state)();

// state function for alarm monitor
STATE_define(AlarmOn);
STATE_define(AlarmOff);

#endif /* ALARM_MONITOR_H_ */

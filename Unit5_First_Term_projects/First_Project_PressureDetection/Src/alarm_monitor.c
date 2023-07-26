/*
 * alarm_monitor.c
 *
 *  Created on: Jul 26, 2023
 *      Author: AmrAli
 */


#include "alarm_monitor.h"

void (*AM_state)();

void HighPressure()
{
	AM_state = STATE(AlarmOn);
}

STATE_define(AlarmOff)
{
	AM_state_id = AlarmOff;
	StopAlarm();
}

STATE_define(AlarmOn)
{
	AM_state_id = AlarmOn;
	StartAlarm();
	AM_state = STATE(AlarmOff);
}


/*
 * alarm_actuator.c
 *
 *  Created on: Jul 26, 2023
 *      Author: AmrAli
 */

#include "alarm_actuator.h"
#include "driver.h"

void (*Led_state)();

void Alarm_init()
{
	// init the alarm
	Led_state = STATE(Waiting);
}
void StartAlarm()
{
	Led_state = STATE(LedOn);
}

void StopAlarm()
{
	Led_state = STATE(LedOff);
}

STATE_define(LedOn)
{
	Led_state_id = LedOn;
	Set_Alarm_actuator(0);
	Delay(1500000);
	Set_Alarm_actuator(1);
	Delay(2000000);
	Led_state = STATE(Waiting);
	
}
STATE_define(LedOff)
{
	Led_state_id = LedOff;
	Set_Alarm_actuator(1);
	Led_state = STATE(Waiting);
}

STATE_define(Waiting)
{
	Led_state_id = Waiting;
	Set_Alarm_actuator(1);
	Delay(10000);
}

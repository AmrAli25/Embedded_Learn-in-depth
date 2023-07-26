/*
 * main.c
 *
 *  Created on: Jul 25, 2023
 *      Author: AmrAli
 */

#include "driver.h"
#include "alarm_monitor.h"
#include "alarm_actuator.h"
#include "algo.h"
#include "PrSensor.h"
#include "state.h"

void setup()
{
	//init all drivers
	GPIO_INITIALIZATION();
	//init block
	PrSensor_init();
	alg_state = STATE(HighPreDetected);
	AM_state = STATE(AlarmOff);
	Alarm_init();
}
void main()
{
	setup();
	while(1)
	{
		PrS_state();
		alg_state();
		AM_state();
		Led_state();
	}
}

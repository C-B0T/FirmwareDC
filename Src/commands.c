/*
 * commands.c
 *
 *  Created on: 2 juin 2018
 *      Author: Jérémy
 */

#include "commands.h"

#include "stm32f0xx_hal.h"
#include "inputs.h"
#include "outputs.h"
#include "status.h"

#include "Config.h"

#define KEY_55	(0x55)

/*----------------------------------------------------------------------------*/
/* privates functions                                                         */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Functions                                                                  */
/*----------------------------------------------------------------------------*/

/* General Functions */
void command_Reset (uint8_t *len, uint8_t *data)
{
	if(data[0] == KEY_55)
		HAL_NVIC_SystemReset();
}

void command_EmergencyStop (uint8_t *len, uint8_t *data)
{
	/* Nothing */
}

void command_Ping(uint8_t *len, uint8_t *data)
{
    *len    = 1U;
    data[0] = 0x55;
}

void command_Init (uint8_t *len, uint8_t *data)
{
	/* Nothing */
}

void command_Status (uint8_t *len, uint8_t *data)
{
	*len = 1U;
	data[0] = Status_GetGlobalStatus();
}

void command_Version (uint8_t *len, uint8_t *data)
{
	*len = 1U;
	data[0] = VERSION_MINOR;
	data[1] = VERSION_MAJOR;
}

void command_Config (uint8_t *len, uint8_t *data)
{
	*len = 5U;
	data[0] = conf[0];
	data[1] = conf[1];
	data[2] = 0x00;
	data[3] = 0x00;
	data[4] = 0x00;
}


void command_GetInputs (uint8_t *len, uint8_t *data)
{
	inputs_GetDirectData_Raw(len, data);
}

void command_SetOutputs (uint8_t *len, uint8_t *data)
{
	uint8_t outputs_raw[2] = {0};

	outputs_raw[0] = data[0];
	outputs_raw[1] = data[1];

    outputs_Write(1, outputs_raw[0]);
    outputs_Write(2, outputs_raw[1]);
}

void command_SetOutput (uint8_t *len, uint8_t *data)
{
	uint8_t unit = data[0];
	uint8_t output_raw = data[1];

    outputs_Write(unit, output_raw);
}




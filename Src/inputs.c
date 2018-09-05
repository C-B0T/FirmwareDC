/*
 * inputs.c
 *
 *  Created on: 27 mai 2018
 *      Author: Jérémy
 */

#include "inputs.h"


uint8_t inputs_raw[INPUTS_LEN] = {0};
uint8_t inputs_lin[INPUTS_LEN] = {0};

// TODO: Proposer des getter de pointer et de taille sur les données

void inputs_Init(void)
{

}

void inputs_UpdateData(void)
{
	uint8_t i = 0;

	for(i=0 ; i < INPUTS_LEN ; i++)
		inputs_raw[i] = inputs_Read(i+1);

	for(i=0 ; i < INPUTS_LEN ; i++)
		inputs_lin[i] = inputs_raw[i];

}

int8_t inputs_GetData_Raw(uint8_t *len, uint8_t *data)
{
	uint8_t i = 0;

	*len = INPUTS_LEN;

	for(i=0 ; i < INPUTS_LEN ; i++)
		data[i] = inputs_raw[i];
    
    return 0;  /*okay*/
}

int8_t inputs_GetData_Lin(uint8_t* len, uint8_t *data)
{
	uint8_t i = 0;

	*len = INPUTS_LEN;

	for(i=0 ; i < INPUTS_LEN ; i++)
		data[i] = inputs_lin[i];

    return 0;  /*okay*/
}

int8_t inputs_GetDirectData_Raw(uint8_t *len, uint8_t *data)
{
	uint8_t i = 0;

	*len = INPUTS_LEN;

	for(i=0 ; i < INPUTS_LEN ; i++)
		data[i] = inputs_raw[i] = inputs_Read(i+1);

    return 0;  /*okay*/
}


uint8_t inputs_Read(enum dio unit)
{
	uint8_t val = 0;
	int8_t err = 0; /*no err*/

	// Try analog resolution and then digital resolution

	if(err < 0)
		err = dio_Digital_Read(unit, &val);

	return val;
}

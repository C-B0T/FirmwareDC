/*
 * inputs.h
 *
 *  Created on: 27 mai 2018
 *      Author: Jérémy
 */

#ifndef INC_INPUTS_H_
#define INC_INPUTS_H_

#include <stdint.h>

#include "dio.h"

#define INPUTS_LEN	(4)

// Table has direct access to optimize time access during SMBUS READ Command
//extern uint8_t inputs_raw[INPUTS_LEN];
//extern uint8_t inputs_lin[INPUTS_LEN];

// Init and Process
void inputs_Init(void);
void inputs_UpdateData(void);

// Accessors
int8_t inputs_GetData_Raw(uint8_t *len, uint8_t *data);
int8_t inputs_GetData_Lin(uint8_t *len, uint8_t *data);

int8_t inputs_GetDirectData_Raw(uint8_t *len, uint8_t *data);

// Functions
uint8_t inputs_Read(enum dio unit);

#endif /* INC_INPUTS_H_ */

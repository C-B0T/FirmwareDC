/*
 * outputs.h
 *
 *  Created on: 27 mai 2018
 *      Author: Jérémy
 */

#ifndef INC_OUTPUTS_H_
#define INC_OUTPUTS_H_

#include <stdint.h>

#include "dio.h"

void outputs_Init(void);

void outputs_Write(uint8_t unit, uint8_t val);

#endif /* INC_OUTPUTS_H_ */

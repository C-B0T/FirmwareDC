/*
 * commands.h
 *
 *  Created on: 2 juin 2018
 *      Author: Jérémy
 */

#ifndef INC_COMMANDS_H_
#define INC_COMMANDS_H_

#include <stdint.h>

void command_Reset         (uint8_t *len, uint8_t *data);
void command_EmergencyStop (uint8_t *len, uint8_t *data);
void command_Ping          (uint8_t *len, uint8_t *data);
void command_Init          (uint8_t *len, uint8_t *data);
void command_Status        (uint8_t *len, uint8_t *data);
void command_Version       (uint8_t *len, uint8_t *data);
void command_Config        (uint8_t *len, uint8_t *data);

void command_GetInputs     (uint8_t *len, uint8_t *data);
void command_SetOutputs    (uint8_t *len, uint8_t *data);
void command_SetOutput     (uint8_t *len, uint8_t *data);

#endif /* INC_COMMANDS_H_ */

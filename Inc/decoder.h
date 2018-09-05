/**
 * @file    decoder.h
 * @author  C-Bot
 * @date    31 mai 2018
 * @brief   Commands decoder
 */

#ifndef INC_DECODER_H_
#define INC_DECODER_H_

#include <stdint.h>
#include "cmsis_os.h"

typedef struct cmd {
	uint8_t  cmd;
	uint8_t  len;
	uint8_t* data;
} cmd_t;

void decoder_Init(osMessageQId* Qx);

void decoder_Process(void);

uint8_t decoder_isWR(uint8_t cmd);

int8_t decoder_GetData(uint8_t cmd, uint8_t *len, uint8_t *data);
int8_t decoder_Decode(uint8_t cmd, uint8_t len, uint8_t *data);


#endif /* INC_DECODER_H_ */

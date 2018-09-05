/*
 * outputs.c
 *
 *  Created on: 27 mai 2018
 *      Author: Jérémy
 */

#include "outputs.h"

void outputs_Init(void)
{

}

void outputs_Write(uint8_t unit, uint8_t val)
{
	int8_t err = 0; /*no err*/
	enum dio dio = dio_GetDIO(unit);

	// Try analog resolution and then digital resolution

	if(err < 0)
		err = dio_Digital_Write(dio, val);
    
    // TODO: Retourner err pour savoir si on est autorisé à écrire sur la sortie (utile au debug)
}


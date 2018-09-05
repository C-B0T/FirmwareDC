/**
 * @file    decoder.c
 * @author  C-Bot
 * @date    31 may 2018
 * @brief   decode cmd
 */

#include "decoder.h"

#include <stddef.h>

#include "stm32f0xx_hal.h"


#include "commands.h"
#include "inputs.h"
#include "status.h"

/*----------------------------------------------------------------------------*/
/* Definitions                                                                */
/*----------------------------------------------------------------------------*/

#define BUFFER_SIZE (10)

#define false	(0U)
#define true	(1U)

#define WR (1U)
#define RD (2U)

#define PING_LEN  (1)
#define PING_KEY  (0x55)

/*----------------------------------------------------------------------------*/
/* Private Members                                                            */
/*----------------------------------------------------------------------------*/

// Status :
//   0x01 : Initialized
//   0x02 : Running
//   0x04 : -
//   0x08 : -
//   0x10 : Error
//   0x20 : -
//   0x40 : -
//   0x80 : -
static uint8_t decoder_status = 0x00;

static osMessageQId* _QxCmd = NULL;

/*----------------------------------------------------------------------------*/
/* Special Reads                                                                 */
/*----------------------------------------------------------------------------*/

//static uint8_t stress[128] = {0, 1, 2, ...};

/*----------------------------------------------------------------------------*/
/* Private Functions                                                          */
/*----------------------------------------------------------------------------*/

uint8_t decoder_GetIndex(uint8_t cmd);



/*----------------------------------------------------------------------------*/
/* Callback Type and Tab                                                      */
/*----------------------------------------------------------------------------*/

typedef struct command {
    uint8_t  cmd;
    uint8_t  dir;
    void(*pF)(uint8_t* len, uint8_t* data);
} command_t;

static const command_t const TabCommand[] = {
	/* General */
	{0x00, WR, command_Reset          },   /* Reset */
	{0x01, WR, command_EmergencyStop  },   /* Emergency Stop */
	{0x02, RD, command_Ping           },   /* Ping */
	{0x03, WR, command_Init           },   /* Init */
	{0x04, RD, command_Status         },   /* Status */
//	{0x05, RD, command_Version        },   /* Version */
//	{0x06, RD, command_Config         },   /* Config */

	/* Servo */
	{0x10, RD, command_GetInputs    },   /* Get Inputs */
	{0x11, WR, command_SetOutputs   },   /* Set Outputs */
	{0x12, WR, command_SetOutput    },   /* Set output */

//	{0xFE, RD, command_Stress  },   /* Stress */
	{0xFF, 0, NULL},    /* Tab end */
};


/*----------------------------------------------------------------------------*/
/* Implementation                                                             */
/*----------------------------------------------------------------------------*/

void decoder_Init(osMessageQId* Qx)
{
	_QxCmd = Qx;
    
	decoder_status |= (1<<0);
}

void decoder_Process(void)
{

}

int8_t decoder_GetData(uint8_t cmd, uint8_t *len, uint8_t *data)
{
	uint8_t i = 0;

    // 1- Search the command
	i = decoder_GetIndex(cmd);

    // 2- Check tab function pointer
    // (optional)

    // 3- Call the function and transfer params (ie: inputs_GetData_Raw(len, pData);)
	if(TabCommand[i].pF != NULL)
		TabCommand[i].pF(len, data);

    return 0; /*okay*/
}

int8_t decoder_Decode(uint8_t cmd, uint8_t len, uint8_t *data)
{
	uint8_t i = 0;

	// 1- Search the command
	i = decoder_GetIndex(cmd);

    // 2- Check tab function pointer
    // (optional)

    // 3- Call the function and transfer params (ie: inputs_SetOutputs(len, pData);)
	if(TabCommand[i].pF != NULL)
		TabCommand[i].pF(&len, data);

    // 4a- The function execute the fast/direct action (simple action)
    // 4b- The function push the action in Qx of Actions (complex action)
    // (done during call step 3)

    return 0; /*okay*/
}


void _decoder_PushCmd(uint8_t cmd, uint8_t len, uint8_t *data)
{

}


// Retro-compatibility

uint8_t decoder_GetIndex(uint8_t cmd)
{
	uint8_t i = 0;

	while((TabCommand[i].cmd != cmd) && (TabCommand[i].cmd != 0xFF))
		i += 1U;

	return i;
}

uint8_t decoder_GetRDWR(uint8_t cmd)
{
	uint8_t i = 0;
	uint8_t rdwr = 0;

	i = decoder_GetIndex(cmd);

	rdwr = TabCommand[i].dir;

	return rdwr;
}
uint8_t decoder_isWR(uint8_t cmd)
{
	uint8_t rdwr = decoder_GetRDWR(cmd);

	if(rdwr == WR)
		return true;
	else
		return false;
}

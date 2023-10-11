/*
 * sct.c
 *
 *  Created on: Oct 11, 2023
 *      Author: xsvece00
 */
#include "main.h"
#include "sct.h"

void sct_init()
{
	sct_led(0);
}

static void tick()
{
	HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 0);
	HAL_GPIO_WritePin(SCT_CLK_GPIO_Port, SCT_CLK_Pin, 1);
}

// value = 0b0001101010.... 32b
void sct_led(uint32_t value)
{

	for(uint32_t i = 0; i < 32; i++)
	{
		if((value >> i) & 1)
		{
			HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, 1);
			tick();
		}
		else
		{
			HAL_GPIO_WritePin(SCT_SDI_GPIO_Port, SCT_SDI_Pin, 0);
			tick();
		}
	}
	HAL_GPIO_WritePin(SCT_NLA_GPIO_Port, SCT_NLA_Pin, 1);
}

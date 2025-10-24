/*
 * screen_ui.h
 *
 *  Created on: Oct 24, 2025
 *      Author: osiko
 */

#ifndef INC_SCREEN_UI_H_
#define INC_SCREEN_UI_H_

#include "stdint.h"
void Screen_UI_Init(void);
void Screen_UI_Display_Values(uint8_t percentage, uint16_t servo_pulse);
#endif /* INC_SCREEN_UI_H_ */

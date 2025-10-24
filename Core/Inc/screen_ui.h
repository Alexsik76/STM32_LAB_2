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
/**
 * @brief Оновлює екран значеннями ШІМ та останньою натиснутою клавішею.
 * @param key Остання натиснута клавіша.
 * @param percentage Значення для B8 у відсотках (10-70).
 * @param servo_pulse Значення для A7 у мікросекундах (650-2500).
 */
// <--- ЗМІНА: Додано параметр 'key'
void Screen_UI_Display_Values(char key, uint8_t percentage, uint16_t servo_pulse);
#endif /* INC_SCREEN_UI_H_ */

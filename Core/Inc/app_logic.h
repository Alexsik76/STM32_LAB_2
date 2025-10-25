/*
 * app_logic.h
 *
 *  Created on: Oct 21, 2025
 *      Author: osiko
 */

#ifndef INC_APP_LOGIC_H_
#define INC_APP_LOGIC_H_

#include <stdint.h>

#define LAB_MIN_PULSE 2000
#define LAB_MAX_PULSE 14000
#define SERVO_MIN_PULSE 650
#define SERVO_MAX_PULSE 2500



typedef struct {
    uint32_t lab_pulse;
    uint32_t servo_pulse;
} App_Pulse_Values_t;

App_Pulse_Values_t App_Process_Keypress(char pressed_key);

uint32_t App_Get_Lab_Pulse(char pressed_key);

uint32_t App_Map_Pulse_For_Servo(uint32_t lab_pulse);

/**
  * @brief  Перетворює (масштабує) значення з одного діапазону в інший.
  * @param  x: Вхідне значення, яке потрібно перетворити.
  * @param  in_min: Нижня межа вхідного діапазону.
  * @param  in_max: Верхня межа вхідного діапазону.
  * @param  out_min: Нижня межа вихідного діапазону.
  * @param  out_max: Верхня межа вихідного діапазону.
  * @retval Масштабоване значення у вихідному діапазоні.
  */
long map(long x, long in_min, long in_max, long out_min, long out_max);

#endif /* INC_APP_LOGIC_H_ */

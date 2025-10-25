/*
 * app_logic.c
 *
 *  Created on: Oct 21, 2025
 *      Author: osiko
 */


#include "main.h"
#include "app_logic.h"



long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	if (in_max == in_min) {
	    return out_min;
	  }
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


/**
  * @brief  Розраховує і повертає значення ШІМ для серво на основі клавіші.
  * @param  key: Символ натиснутої клавіші.
  * @retval Значення для регістра CCR таймера.
  */
uint32_t App_Get_Lab_Pulse(char key)
{
  static uint32_t current_lab_pulse = LAB_MIN_PULSE;

  switch (key)
  {
	case '1':
	case '*':
		current_lab_pulse = LAB_MIN_PULSE;
		break;
	case '2': current_lab_pulse = 3500;  break;
	case '3': current_lab_pulse = 5000;  break;
	case '4': current_lab_pulse = 6500;  break;
	case '5': current_lab_pulse = 8000;  break;
	case '6': current_lab_pulse = 9500;  break;
	case '7': current_lab_pulse = 11000; break;
	case '8': current_lab_pulse = 12500; break;
	case '9':
	case '#':
		current_lab_pulse = LAB_MAX_PULSE;
		break;
	default: break;
  }
  return current_lab_pulse;
}

uint32_t App_Map_Pulse_For_Servo(uint32_t lab_pulse)
{
    return map(lab_pulse, LAB_MIN_PULSE, LAB_MAX_PULSE, SERVO_MIN_PULSE, SERVO_MAX_PULSE);
}

/**
  * @brief  Обробляє натискання клавіші та повертає всі розраховані значення ШІМ.
  * @param  pressed_key: Символ натиснутої клавіші.
  * @retval Структура App_Pulse_Values_t з усіма значеннями.
  */
App_Pulse_Values_t App_Process_Keypress(char pressed_key)
{
    App_Pulse_Values_t values;

    // 1. Отримуємо імпульс для лабораторної
    // (Ця функція вже має 'static' змінну, тому вона пам'ятає стан)
    values.lab_pulse = App_Get_Lab_Pulse(pressed_key);

    // 2. Розраховуємо імпульс для серво
    values.servo_pulse = App_Map_Pulse_For_Servo(values.lab_pulse);

    return values;
}

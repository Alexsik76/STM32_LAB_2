/*
 * app_logic.c
 *
 *  Created on: Oct 21, 2025
 *      Author: osiko
 */


#include "main.h"
#include "app_logic.h"



static long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


static uint32_t blink_start_time = 0; // Час початку блимання
static uint8_t is_blinking = 0;       // Прапор, що світлодіод зараз блимає

/**
 * @brief Вмикає світлодіод для зворотного зв'язку (початок блимання).
 */
void App_Blink_Start(void)
{
  HAL_GPIO_WritePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin, GPIO_PIN_RESET); // Увімкнути
  blink_start_time = HAL_GetTick(); // Запам'ятати час
  is_blinking = 1;                  // Встановити прапор
}

/**
 * @brief Перевіряє, чи час блимання вийшов, і вимикає світлодіод.
 * Викликати у головному циклі.
 */
void App_Blink_Check_End(void)
{
  if (is_blinking && (HAL_GetTick() - blink_start_time >= 50)) // Якщо блимає і пройшло 50 мс
  {
    HAL_GPIO_WritePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin, GPIO_PIN_SET); // Вимкнути
    is_blinking = 0; // Скинути прапор
  }
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

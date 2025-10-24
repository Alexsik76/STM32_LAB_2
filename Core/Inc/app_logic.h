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


/**
 * @brief Вмикає світлодіод для зворотного зв'язку (початок блимання).
 */
void App_Blink_Start(void);

/**
 * @brief Перевіряє, чи час блимання вийшов, і вимикає світлодіод.
 * Викликати у головному циклі.
 */
void App_Blink_Check_End(void);

uint32_t App_Get_Lab_Pulse(char key);
uint32_t App_Map_Pulse_For_Servo(uint32_t lab_pulse);

#endif /* INC_APP_LOGIC_H_ */

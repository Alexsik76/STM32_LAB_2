/*
 * keypad.h
 *
 * Created on: Oct 21, 2025
 * Author: osiko
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#include "main.h"

typedef enum {
    KEY_STATE_IDLE,       // 0: Чекаємо натискання
    KEY_STATE_DEBOUNCING_PRESS, // 1: Йде 50мс "анти-брязкіт"
    KEY_STATE_READY,       // 2: Ключ готовий до обробки
	KEY_STATE_WAIT_FOR_RELEASE,
	KEY_STATE_DEBOUNCING_RELEASE
} Keypad_State_t;

/**
  * @brief  Сканує клавіатуру (без затримок) для визначення натиснутої клавіші.
  * @retval Символ клавіші ('0'-'9', 'A'-'D', '*', '#') або '\0', якщо нічого не натиснуто.
  */
char Keypad_Get_Pressed_Key_NO_DELAY(void);


extern volatile Keypad_State_t g_keypad_state;
extern volatile char g_keypad_last_key;

#endif /* INC_KEYPAD_H_ */

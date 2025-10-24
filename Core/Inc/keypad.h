/*
 * keypad.h
 *
 *  Created on: Oct 21, 2025
 *      Author: osiko
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_
typedef enum {
    KEY_STATE_IDLE,       // 0: Чекаємо натискання
    KEY_STATE_DEBOUNCING, // 1: Йде 50мс "анти-брязкіт"
    KEY_STATE_READY       // 2: Ключ готовий до обробки
} Keypad_State_t;
char Keypad_Get_Pressed_Key_NO_DELAY(void);
extern volatile Keypad_State_t g_keypad_state;
extern volatile char g_keypad_last_key;
extern TIM_HandleTypeDef htim2;
#endif /* INC_KEYPAD_H_ */

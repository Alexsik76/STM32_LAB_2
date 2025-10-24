/*
 * keypad.c
 *
 *  Created on: Oct 21, 2025
 *      Author: osiko
 */


#include "main.h"

static const char keys[4][4] = {
  {'1', '2', '3', 'A'}, {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}
};

static const uint16_t row_pins[4] = {GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_11}; // PA8-PA11
static const uint16_t col_pins[4] = {GPIO_PIN_12, GPIO_PIN_13, GPIO_PIN_14, GPIO_PIN_15}; // PB12-PB15

/**
  * @brief  Сканує клавіатуру і повертає символ натиснутої клавіші.
  * @retval Символ клавіші або '\0', якщо нічого не натиснуто.
  */
// У Core/Src/keypad.c, у функції Keypad_Get_Pressed_Key_NO_DELAY
char Keypad_Get_Pressed_Key_NO_DELAY(void) {


  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_SET);

  for (int c = 0; c < 4; c++) {
    // КРОК 2: Активуємо поточний стовпець (LOW) для сканування
    HAL_GPIO_WritePin(GPIOB, col_pins[c], GPIO_PIN_RESET);

    for (int r = 0; r < 4; r++) {
      if (HAL_GPIO_ReadPin(GPIOA, row_pins[r]) == GPIO_PIN_RESET) {

        // КРОК 3: КЛАВІША ЗНАЙДЕНА. Повертаємо ВСІ стовпці в стан очікування (LOW) перед виходом
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

        return keys[r][c];
      }
    }
    // КРОК 4: Деактивуємо поточний стовпець (HIGH) для переходу до наступного
    HAL_GPIO_WritePin(GPIOB, col_pins[c], GPIO_PIN_SET);
  }

  // КРОК 5: Якщо нічого не знайдено, повертаємо ВСІ стовпці в стан очікування (LOW)
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  return '\0';
}

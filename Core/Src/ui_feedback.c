/*
 * ui_feedback.c
 *
 * Created on: Oct 25, 2025
 * Author: osiko
 */

#include "ui_feedback.h"

/**
 * @brief Вмикає світлодіод для зворотного зв'язку (початок блимання).
 */
void UI_Blink_Start(void)
{
  // Увімкнути світлодіод (встановити пін в '0' для Blue Pill)
  HAL_GPIO_WritePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin, GPIO_PIN_RESET);
}

/**
 * @brief Перевіряє, чи час блимання вийшов, і вимикає світлодіод.
 * Викликати у головному циклі.
 */
void UI_Blink_End(void)
{
    // Вимкнути світлодіод (встановити пін в '1' для Blue Pill)
    HAL_GPIO_WritePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin, GPIO_PIN_SET);
}

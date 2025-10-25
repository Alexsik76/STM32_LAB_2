/*
 * ui_feedback.h
 *
 * Created on: Oct 25, 2025
 * Author: osiko
 */

#ifndef INC_UI_FEEDBACK_H_
#define INC_UI_FEEDBACK_H_

#include "main.h" // Потрібен для HAL

/**
 * @brief Вмикає світлодіод для зворотного зв'язку (початок блимання).
 */
void UI_Blink_Start(void);

/**
 * @brief Перевіряє, чи час блимання вийшов, і вимикає світлодіод.
 * Викликати у головному циклі.
 */
void UI_Blink_End(void);


#endif /* INC_UI_FEEDBACK_H_ */

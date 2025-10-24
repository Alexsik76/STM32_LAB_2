/*
 * screen_ui.c
 *
 *  Created on: Oct 24, 2025
 *      Author: osiko
 */


#include "screen_ui.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "stdio.h" // Для sprintf

/**
 * @brief Ініціалізує дисплей та виводить стартове повідомлення.
 */
void Screen_UI_Init(void) {
    // Ініціалізуємо дисплей
    ssd1306_Init();

    // Виводимо стартовий екран
    ssd1306_Fill(Black); // Очищуємо буфер
    ssd1306_SetCursor(0, 0);
    ssd1306_WriteString("ZPI-ZP-31", Font_11x18, White);
    ssd1306_SetCursor(0, 25);
    ssd1306_WriteString("Starting...", Font_7x10, White);

    // Відображаємо буфер на екрані
    ssd1306_UpdateScreen();
}

/**
 * @brief Оновлює екран значеннями ШІМ для пінів B8 та A7.
 * @param percentage Значення для B8 у відсотках (10-70).
 * @param servo_pulse Значення для A7 у мікросекундах (650-2500).
 */
void Screen_UI_Display_Values(uint8_t percentage, uint16_t servo_pulse) { // <--- Нова назва та параметри
	char buffer_b8[20]; // Буфер для рядка B8
	char buffer_a7[20]; // Буфер для рядка A7

	    // --- Форматуємо рядки ОДРАЗУ з назвою піна ---
	    sprintf(buffer_b8, "B8: %u %%", (unsigned int)percentage);     // Напр.: "B8: 55 %"
	    sprintf(buffer_a7, "A7: %u us", (unsigned int)servo_pulse); // Напр.: "A7: 1500 us"

	    // Очищуємо буфер
	    ssd1306_Fill(Black); //

	    // --- Верхня (жовта) зона - Заголовок ---
	    ssd1306_SetCursor(0, 0); // Починаємо з самого верху
	    ssd1306_WriteString("Lab 2", Font_11x18, White); // Використовуємо менший шрифт

	    // --- Нижня (синя) зона ---
	    // Починаємо виводити дані нижче жовтої зони (припустимо, вона ~16-20 пікселів)
	    ssd1306_SetCursor(0, 25); // Спробуємо Y=25 для першого рядка даних
	    ssd1306_WriteString(buffer_b8, Font_7x10, White); // Виводимо "B8: XX %"

	    ssd1306_SetCursor(0, 40); // Спробуємо Y=40 для другого рядка даних (10 пікс шрифт + 5 пікс проміжок)
	    ssd1306_WriteString(buffer_a7, Font_7x10, White); // Виводимо "A7: XXXX us"

	    // Оновлюємо фізичний екран
	    ssd1306_UpdateScreen(); //
}

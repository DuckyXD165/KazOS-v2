#ifndef PRINTF_H
#define PRINTF_H

/**
 * @brief Prints formatted output to the console.
 * 
 * This function supports a subset of format specifiers:
 *   - %s: String specifier
 *   - %%: Percent sign (literal)
 * 
 * Newline character (\n) is also supported for printing new lines.
 * 
 * @param format A format string containing format specifiers.
 * @param ... Variable number of arguments corresponding to the format specifiers.
 */
void printf(const char *format, ...);

/**
 * @brief Prints a single character to the console.
 * 
 * @param chara The character to be printed.
 */
void printChar(char chara);

/**
 * @brief Prints a null-terminated string to the console.
 * 
 * @param str Pointer to the null-terminated string to be printed.
 */
void printString(const char *str);

/**
 * @brief Moves the cursor to the start of the next line.
 * 
 * If the cursor reaches the end of the screen, this function scrolls the screen up by one line.
 */
void newLine();

/**
 * @brief Scrolls the screen up by one line.
 * 
 * The last line of the screen is cleared, and each line is shifted up by one line.
 */
void scrollScreen();

#endif /* PRINTF_H */

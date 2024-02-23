#include "printf.h"
#define VIDEO_MEMORY_ADDRESS 0xB8000
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
static int cursor = 0;
void printf(const char *format, ...) {
    // Pointer to traverse the format string
    if (cursor > (SCREEN_WIDTH*SCREEN_HEIGHT)) {
    newLine();
}
    const char *ptr = format;

    // Initialize variable arguments
    void *args = (void *)&format + sizeof(format);

    // Process each character in the format string
    while (*ptr != '\0') {
        // If current character is '%', it indicates a format specifier
        if (*ptr == '%') {
            ptr++; // Move to next character
            // Handle different format specifiers
            switch (*ptr) {
                case 's': {
                    // Print string argument
                    char *str_arg = *((char **)args);
                    printString(str_arg);
                    args += sizeof(char *);
                    break;
                }
                default:
                    // Unsupported format specifier, just print '%'
                    printChar('%');
            }
        } else if (*ptr == '\n') {
            // If current character is newline, move cursor to the start of the next line
            newLine();
        } else {
            // Print normal characters
            printChar(*ptr);
        }
        ptr++; // Move to next character in format string
    }
}


void printChar(char chara) {
    char *video_memory = (char *)0xB8000;
    char letter = chara;

    // Attribute byte: white on black
    unsigned char attribute_byte = 0x0F;

    // Write the letter to the video memory
    *(video_memory + (cursor * 2)) = letter;
    // Next byte is the attribute byte
    *(video_memory + (cursor * 2) + 1) = attribute_byte;

    // Move cursor to the next position
    cursor++;
}

void printString(const char *str) {
    // Print each character in the string
    while (*str != '\0') {
        printChar(*str);
        str++;
    }
}

void newLine() {
    
    cursor = (cursor / 80 + 1) * 80; // Move cursor to the start of the next line
    if (cursor >= 80 * 25) {
        // If the cursor reaches the end of the screen, scroll the screen up
        scrollScreen();
        cursor = 80 * 24; // Move cursor to the last line
    }
}

void scrollScreen() {
    // Pointer to video memory
    char *video_memory = (char *)VIDEO_MEMORY_ADDRESS;
    
    // Copy each line to the line above it
    for (int y = 1; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            // Calculate the offset for the current character in the video memory
            int offset_current = (y * SCREEN_WIDTH + x) * 2;
            // Calculate the offset for the character one line above in the video memory
            int offset_above = ((y - 1) * SCREEN_WIDTH + x) * 2;
            // Copy the character and its attributes from one line above
            video_memory[offset_above] = video_memory[offset_current];
            video_memory[offset_above + 1] = video_memory[offset_current + 1];
        }
    }

    // Clear the last line
    for (int x = 0; x < SCREEN_WIDTH; x++) {
        // Calculate the offset for the last line in the video memory
        int offset_last_line = ((SCREEN_HEIGHT - 1) * SCREEN_WIDTH + x) * 2;
        // Clear the character
        video_memory[offset_last_line] = ' ';
        // Set default attribute (white on black)
        video_memory[offset_last_line + 1] = 0x0F;
    }
}
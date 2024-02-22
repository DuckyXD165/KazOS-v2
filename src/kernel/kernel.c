void initKernel() {
    // Example usage of printf function
    printf("H -Bootloader");

    hlt();
}

void printf(const char *format, ...) {
    // Pointer to traverse the format string
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
        } else {
            // Print normal characters
            printChar(*ptr);
        }
        ptr++; // Move to next character in format string
    }
}

void printChar(char chara) {
    char *video_memory = (char *)0xB8000;
    static int cursor = 0; // Static variable to keep track of cursor position
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

void hlt() {
    while (1) {
        asm volatile("hlt");
    }
}
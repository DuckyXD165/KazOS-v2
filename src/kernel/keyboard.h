#ifndef KEYBOARD_H
#define KEYBOARD_H

// Keyboard data port address
#define KEYBOARD_DATA_PORT 0x60

// Function to process a keyboard scan code
void process_key(unsigned char scan_code);

// Function to initialize the keyboard
void keyboard_init();

// Function to check if keyboard data is available
int is_keyboard_data_available();

// Function to read the keyboard scan code
unsigned char read_keyboard_scan_code();

// Function to enable keyboard interrupts
void enable_keyboard_interrupts();

// Function to disable keyboard interrupts
void disable_keyboard_interrupts();

// Function to handle keyboard interrupt
void keyboard_interrupt_handler();

#endif // KEYBOARD_H
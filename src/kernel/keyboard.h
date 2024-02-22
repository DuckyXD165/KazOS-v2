#ifndef KEYBOARD_H
#define KEYBOARD_H

// Define the keyboard data port address
#define KEYBOARD_DATA_PORT 0x60

// Function prototypes
unsigned char inportb(unsigned short port);
void keyboard_init();
void keyboard_interrupt_handler();
void enable_keyboard_interrupts();
void disable_keyboard_interrupts();
int is_keyboard_data_available();
unsigned char read_keyboard_scan_code();
void process_key(unsigned char scan_code);
unsigned char inportb(unsigned short port);
#endif /* KEYBOARD_H */

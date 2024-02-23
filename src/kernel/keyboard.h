#ifndef KEYBOARD_H
#define KEYBOARD_H

// Define the keyboard data port address
#define KEYBOARD_DATA_PORT 0x60

// Function prototypes
void keyboard_init();
void keyboard_interrupt_handler();
void enable_keyboard_interrupts();
void disable_keyboard_interrupts();
int is_keyboard_data_available();
unsigned char read_keyboard_scan_code();
void process_key(unsigned char scan_code);
void outportb(unsigned short port, unsigned char value);
unsigned char inportb(unsigned short port) {
    unsigned char value;
    __asm__ __volatile__("inb %1, %0" : "=a"(value) : "dN"(port));
    return value;
}

#endif /* KEYBOARD_H */
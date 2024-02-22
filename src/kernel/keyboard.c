// Define the keyboard data port address
#include "keyboard.h"
#include "printf.h"


void process_key(unsigned char scan_code) {
    // Example: Print the scan code as a hexadecimal value
    printf("Scan code: 0x%X\n", scan_code);
}

// Implement the functions declared in keyboard.h

void keyboard_init() {
    printf("Keyboard is initializing");
}

void keyboard_interrupt_handler() {
    // You would typically implement this in your kernel's interrupt handling routine
    // Read the scan code and process it
    unsigned char scan_code = read_keyboard_scan_code();
    // Process the scan code
    process_key(scan_code);
}

void enable_keyboard_interrupts() {
    // You would implement this to enable interrupts on the keyboard controller
    // For example, for PS/2 keyboard, you would send a command to enable interrupts
}

void disable_keyboard_interrupts() {
    // You would implement this to disable interrupts on the keyboard controller
}

int is_keyboard_data_available() {
    // Read the status register to check if there is data available in the keyboard buffer
    unsigned char status = inportb(0x64);
    return status & 0x01; // Check the least significant bit
}

unsigned char read_keyboard_scan_code() {
    // Wait until the keyboard has data available
    while (!is_keyboard_data_available());

    // Read the scan code from the keyboard data port
    unsigned char scan_code = inportb(KEYBOARD_DATA_PORT);
    return scan_code;
}

unsigned char inportb(unsigned short port) {
    unsigned char value;
    __asm__ __volatile__("inb %1, %0" : "=a"(value) : "dN"(port));
    return value;
}


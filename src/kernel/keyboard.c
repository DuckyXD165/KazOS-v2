// Define the keyboard data port address
#include "keyboard.h"
#include "printf.h"

void process_key(unsigned char scan_code) {
    // Example: Print the scan code as a hexadecimal value
    printf("Scan code: 0x%X\n", scan_code);
}

// Implement the functions declared in keyboard.h

void keyboard_init() {
    printf("Keyboard is initializing...\n");
    // Additional initialization steps can be performed here if needed
}

void keyboard_interrupt_handler() {
    unsigned char scan_code = read_keyboard_scan_code();
    // Process the scan code
    process_key(scan_code);
}

void enable_keyboard_interrupts() {
    // Enable keyboard interrupts by sending the appropriate command to the keyboard controller
    outportb(0x64, 0xAE); // Command to enable keyboard interrupts
}

void disable_keyboard_interrupts() {
    // Disable keyboard interrupts by sending the appropriate command to the keyboard controller
    outportb(0x64, 0xAD); // Command to disable keyboard interrupts
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

void outportb(unsigned short port, unsigned char value) {
    __asm__ __volatile__("outb %0, %1" ::"a"(value), "dN"(port));
}
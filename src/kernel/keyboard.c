// Define the keyboard data port address
#include "keyboard.h"
#include "printf.h"
#include "portio.h"

// Function to process key
void process_key(unsigned char scan_code) {
    // Handle specific scan codes
    switch (scan_code) {
        case 0x01: // Escape key
            // Perform actions for the Escape key
            // ...
            break;
        case 0x02: // 1 key
            // Perform actions for the 1 key
            // ...
            break;
        case 0x03: // 2 key
            // Perform actions for the 2 key
            // ...
            break;
        case 0x10: // Q key
            // Perform actions for the Q key
            // ...
            break;
        case 0x11: // W key
            // Perform actions for the W key
            // ...
            break;
        case 0x12: // E key
            // Perform actions for the E key
            // ...
            break;
        // Add more cases for other keys as needed
        // ...
        default:
            // Unknown or unhandled scan code
            break;
    }
}

// Function to initialize the keyboard
void keyboard_init() {
    printf("Keyboard is initializing...\n");
    enable_keyboard_interrupts();
    // Additional initialization steps can be performed here if needed

    // Wait for the keyboard controller to be ready
    while ((inportb(0x64) & 0x02) != 0)
        ;

    // Enable the keyboard
    outportb(0x64, 0xAE);

    // Wait for the keyboard controller to be ready
    while ((inportb(0x64) & 0x02) != 0)
        ;

    // Enable the keyboard interrupt line
    outportb(0x64, 0x60);

    // Keyboard initialization complete message
    printf("Keyboard initialization complete.\n");
}

// Function to check if keyboard data is available
int is_keyboard_data_available() {
    // Read the status register to check if there is data available in the keyboard buffer
    unsigned char status = inportb(0x64);
    return status & 0x01; // Check the least significant bit
}

// Function to read the keyboard scan code
unsigned char read_keyboard_scan_code() {
    // Wait until the keyboard has data available
    while (!is_keyboard_data_available());

    // Read the scan code from the keyboard data port
    unsigned char scan_code = inportb(KEYBOARD_DATA_PORT);
    return scan_code;
}

// Function to enable keyboard interrupts
void enable_keyboard_interrupts() {
    printf("Keyboard interrupts are Enabled\n");
    // Enable keyboard interrupts by sending the appropriate command to the keyboard controller
    outportb(0x64, 0xAE); // Command to enable keyboard interrupts
}

// Function to disable keyboard interrupts
void disable_keyboard_interrupts() {
    // Disable keyboard interrupts by sending the appropriate command to the keyboard controller
    outportb(0x64, 0xAD); // Command to disable keyboard interrupts
}

// Function to handle keyboard interrupt
void keyboard_interrupt_handler() {
    unsigned char scan_code = read_keyboard_scan_code();
    // Process the scan code
    process_key(scan_code);
}
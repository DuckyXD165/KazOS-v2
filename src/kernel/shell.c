#include "printf.h"
#include "keyboard.h"
#include "kernel.h"

void initShell(){
    printf("Shell is initializing...\n");
    keyboard_init();
    printf("Keyboard has been initialized\n");

    while (1) {
        if (is_keyboard_data_available()) {
            unsigned char scan_code = read_keyboard_scan_code();
            process_key(scan_code);
        }
    }
}
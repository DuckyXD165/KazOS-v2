#include "printf.h"
#include "keyboard.h"

void hlt(); // Function prototype for hlt()

void initKernel() {
    printf("Booting...\n");
    keyboard_init();
    hlt();
}

void hlt() {
    printf("System Has reached end of kernel! Halting CPU...");
    while (1) {
        asm volatile("hlt");
    }
}
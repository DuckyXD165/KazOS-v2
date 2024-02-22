#include "printf.h"
#include "keyboard.h"

void hlt(); // Function prototype for hlt()

void initKernel() {
    printf("Booting...");
    keyboard_init();
    hlt();
}

void hlt() {
    while (1) {
        asm volatile("hlt");
    }
}
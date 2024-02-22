#include "printf.h"

void hlt(); // Function prototype for hlt()

void initKernel() {
    printf("Booting...");
    hlt();
}

void hlt() {
    while (1) {
        asm volatile("hlt");
    }
}
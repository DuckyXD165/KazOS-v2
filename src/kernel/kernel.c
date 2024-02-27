#include "printf.h"
#include "shell.h"

void hlt(); // Function prototype for hlt()

void initKernel() {
    printf("Booting...\n");
    initShell();
    hlt();
}

void hlt() {
    printf("\nSystem has reached end of kernel! Halting CPU...");
    while (1) {
        asm volatile("hlt");
    }
}
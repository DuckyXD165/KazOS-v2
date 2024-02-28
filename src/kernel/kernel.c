#include "printf.h"
#include "shell.h"

void hlt(); // Function prototype for hlt()
void panic();

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

void panic() {
    printf("\nPANIC PANIC PANIC! Halting CPU!");
    while (1) {
        asm volatile("hlt");
    }
}
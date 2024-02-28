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
    printf("\n=== FATAL ERROR: KERNEL PANIC === CPU OPERATION HALTED ===");
    while (1) {
        asm volatile("hlt");
    }
}
#include "printf.h"
#include "shell.h"

void hlt();
void panic();

void initKernel() {
    printf("Booting...\n");
    initShell();
    hlt();
    //panic();
}

void hlt() {
    printf("\nSystem has reached end of kernel! Halting CPU...");
    while (1) {
        asm volatile("hlt");
    }
}

void panic() {
    printf("\nFATAL ERROR / KERNEL PANIC:\n      KazOS has encountered a severe error and cannot continue.\n      CPU operation has been halted for safety.");
    while (1) {
        asm volatile("hlt");
    }
}
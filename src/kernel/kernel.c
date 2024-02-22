#include "printf.h"
#include "kernel.h"
void initKernel() {
    printf("Booting...");
    hlt();
}

void hlt() {
    while (1) {
        asm volatile("hlt");
    }
}
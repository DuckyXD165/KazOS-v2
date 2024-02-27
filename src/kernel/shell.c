#include "printf.h"
#include "kernel.h"

void initShell(){
    printf("Shell is initializing...\n");
    keyboard_init();
    printf("Keyboard has been initialized\n");

    
}
# Introductory
Welcome to the offical KazOS Github repository. This is where the source code to KazOS will be.

## Building KazOS
To Build KazOS follow these steps. This guide assumes you are using Homebrew as a package manager. If you aren't using brew and you need the packages, See "Used Packages".

Step 1: `sudo chmod u+x ./Requirements.txt`

Step 2: `./Requirements.txt`

If brew has installed those packages successfully run the command `make`. KazOS should build and run itself in Qemu



## Used Packages
NASM 

QEMU 

GCC 

GDB 

i586-elf-binutils 

i586-elf-gcc 

i586-elf-gdb


# KazOS Update timeline
Just accomplished jumping to a C kernel. 2/21/24

Added printf function for easier printing to screen. 2/22/24

Added \n Support to printf, Huge thanks to e820 for helping me out. 2/22/24

# Credits
- Aptrock327
- Frothy-Wifi
- DuckyXD165
- e820

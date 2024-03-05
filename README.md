# Introductory
Welcome to the official KazOS Github repository. This is where the source code to KazOS will be.

## Building KazOS
To build KazOS follow these steps. This guide assumes you are using Homebrew as a package manager. If you aren't using brew and you need the packages, See "Used Software". (Note: the software's names may be different from their actual package names, for example a software called Hello may be packaged into `hello-tool`, which is also a horrible name for a package.)  
(Note from @frothy-wifi: I'm making Debian, RPM, and Arch packages that automatically install the below dependencies and provide a tool to build KazOS.)

Step 1: `sudo chmod u+x ./Requirements.sh`

Step 2: `./Requirements.sh`

If brew has installed those packages successfully, run the command `make`. KazOS should build and run itself in QEMU.



## Used Software
GNU Make

NASM 

QEMU 

GCC 

GDB 

i586-elf-binutils 

i586-elf-gcc 

i586-elf-gdb


# KazOS Update Timeline
Just accomplished jumping to a C kernel. 2/21/24

Added printf function for easier printing to screen. 2/22/24

Added \n support to printf, huge thanks to e820 for helping me out. 2/22/24

# Credits
- Aptrock327
- Frothy-Wifi
- DuckyXD165
- e820

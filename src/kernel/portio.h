#ifndef PORTIO_H
#define PORTIO_H

// Function to read from a port
unsigned char inportb(unsigned short port);

// Function to write to a port
void outportb(unsigned short port, unsigned char value);

#endif // PORTIO_H
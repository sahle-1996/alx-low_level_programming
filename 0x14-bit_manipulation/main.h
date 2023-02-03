#ifndef MAIN_H
#define MAIN_H


#include <stdlib.h>


unsigned int rec_bin(const char *, int, int);
int pwr(int, int);
unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int _putchar(char c);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
int get_endianness(void);
unsigned int flip_bits(unsigned long int n, unsigned long int m);


#endif /*MAIN_H*/

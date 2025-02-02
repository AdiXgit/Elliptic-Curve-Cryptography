#ifndef FIELD_MATH_H
#define FIELD_MATH_H

#include <stdio.h>
#include <stdint.h>

#define PRIME 23

// Function declarations
int mod_add(int a, int b);
int mod_sub(int a, int b);
int mod_mul(int a, int b);
int mod_exp(int base, int exp);
int mod_inv(int a);

#endif // FIELD_MATH_H

#ifndef ECC_H
#define ECC_h

#include<stdint.h>
#include "field_math.h" //for modular arithmetic
//defining the eliptic curve parameters

typedef struct{
    int x;int y;
} ec_point;

//curve equation: y^2 = x^3 + ax + b
//curve parameters
#define curve_a 1
#define curve_b 1

//a point at infinity
extern ec_point POINT_INFINITY;

//function declarations
ec_point ecc_add(ec_point p,ec_point q);
ec_point ecc_double(ec_point p);
ec_point ecc_scalar_mul(int k,ec_point p);


#endif /* ECC_H */

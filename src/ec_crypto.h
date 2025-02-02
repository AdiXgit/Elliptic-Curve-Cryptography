#ifndef EC_CRYPTO_H
#define EC_CRYPTO_H

#include "field_math.h"

typedef struct {
    int x;
    int y;
    int is_infinity; // ✅ Ensure all instances of this struct match
} ec_point;

// Function declarations
ec_point ecc_add(ec_point p, ec_point q);
ec_point ecc_double(ec_point p);
ec_point ecc_scalar_mult(ec_point p, int k); // ✅ Ensure function declaration is correct

#endif

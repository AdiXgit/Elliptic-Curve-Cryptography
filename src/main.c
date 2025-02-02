#include <stdio.h>
#include "ec_crypto.h"

int main() {
    ec_point g = {2, 22, 0}; // Generator point, assuming '0' means not at infinity
    int scalar = 3;

    ec_point p2 = ecc_scalar_mult(g, scalar); // ✅ Fixed argument order

    printf("Result: (%d, %d)\n", p2.x, p2.y);
    return 0;
}

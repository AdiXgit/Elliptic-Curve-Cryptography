#include <stdlib.h>
#include <time.h>
#include "keygen.h"

// Function to generate a key pair
void generate_keypair(EllipticCurve curve, int *private_key, Point *public_key) {
    *private_key = rand() % (curve.p - 1) + 1; // Ensure it's non-zero
    *public_key = point_multiply(curve.G, *private_key, curve);
}

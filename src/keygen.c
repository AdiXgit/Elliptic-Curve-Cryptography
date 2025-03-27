#include <stdlib.h>
#include <time.h>
#include "keygen.h"

// Function to generate a key pair
void generate_keypair(EllipticCurve curve, int *private_key, Point *public_key) {
    // Generate a random private key
    *private_key = rand() % (curve.p - 1) + 1; // Ensure it's non-zero
    Point G = {3, 6}; // Example generator point (must be on the curve)
    *public_key = point_multiply(G, *private_key, curve);
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecc.h"
#include "keygen.h"
#include "ecdsa.h"

int main() {
    srand(time(NULL)); // Seed random number generator

    // Define an elliptic curve
    EllipticCurve curve = {2, 3, 97}; // Example curve parameters
    Point G = {3, 6}; // Example generator point (must be on the curve)

    // Check if the generator point is on the curve
    if (!is_point_on_curve(curve, G)) {
        printf("Generator point G is not on the curve.\n");
        return 1; // Exit if G is not valid
    }

    // Generate key pair
    int private_key;
    Point public_key;
    generate_keypair(curve, &private_key, &public_key);

    printf("Private Key: %d\n", private_key);
    printf("Public Key: (%d, %d)\n", public_key.x, public_key.y);

    // Sign a message
    int k = rand() % (curve.p - 1) + 1; // Random k
    int message_hash = 42; // Example message hash
    Signature signature = ecdsa_sign(private_key, k, curve, G, message_hash);
    printf("Signature: (r: %d, s: %d)\n", signature.r, signature.s);

    // Verify the signature
    int is_valid = ecdsa_verify(public_key, signature, message_hash, curve, G);
    printf("Signature valid: %s\n", is_valid ? "Yes" : "No");

    return 0;
}
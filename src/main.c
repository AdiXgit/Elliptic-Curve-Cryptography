#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ecc.h"
#include "keygen.h"
#include "ecdsa.h"

int main() {
    srand(time(NULL));

    // Define an elliptic curve with a generator point
    EllipticCurve curve = {2, 3, 97, {3, 6, 0}};


    // Check if G is valid
    if (!is_point_on_curve(curve, curve.G)) {
        printf("Error: Generator point is not on the curve!\n");
        return 1;
    }

    int private_key;
    Point public_key;
    generate_keypair(curve, &private_key, &public_key);

    printf("Private Key: %d\n", private_key);
    printf("Public Key: (%d, %d)\n", public_key.x, public_key.y);

    int k = rand() % (curve.p - 1) + 1;
    int message_hash = 42;
    Signature signature = ecdsa_sign(private_key, k, curve, curve.G, message_hash);

    printf("Signature: (r: %d, s: %d)\n", signature.r, signature.s);

    int is_valid = ecdsa_verify(public_key, signature, message_hash, curve, curve.G);
    printf("Signature valid: %s\n", is_valid ? "Yes" : "No");

    return 0;
}

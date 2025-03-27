#include <stdlib.h>
#include "ecdsa.h"

// Function to generate a signature
Signature ecdsa_sign(int private_key, int k, EllipticCurve curve, Point G, int message_hash) {
    Signature sig;
    Point R = point_multiply(G, k, curve);
    sig.r = R.x % curve.p;

    // Calculate s
    int k_inv = mod_inverse(k, curve.p - 1);
    sig.s = (k_inv * (message_hash + private_key * sig.r)) % (curve.p - 1);

    return sig;
}

// Function to verify a signature
int ecdsa_verify(Point public_key, Signature signature, int message_hash, EllipticCurve curve, Point G) {
    if (signature.r < 1 || signature.r >= curve.p || signature.s < 1 || signature.s >= (curve.p - 1)) {
        return 0; // Invalid signature
    }

    int w = mod_inverse(signature.s, curve.p - 1);
    int u1 = (message_hash * w) % (curve.p - 1);
    int u2 = (signature.r * w) % (curve.p - 1);

    Point P1 = point_multiply(G, u1, curve);
    Point P2 = point_multiply(public_key, u2, curve);
    Point R = point_add(P1, P2, curve);

    return (R.x % curve.p) == signature.r; // Verify the signature
}
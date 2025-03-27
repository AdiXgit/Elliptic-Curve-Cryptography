#ifndef ECDSA_H
#define ECDSA_H

#include "ecc.h"

typedef struct {
    int r;
    int s;
} Signature;

Signature ecdsa_sign(int private_key, int k, EllipticCurve curve, Point G, int message_hash);
int ecdsa_verify(Point public_key, Signature signature, int message_hash, EllipticCurve curve, Point G);

#endif // ECDSA_H
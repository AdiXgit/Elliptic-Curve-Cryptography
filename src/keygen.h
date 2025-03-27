#ifndef KEYGEN_H
#define KEYGEN_H

#include "ecc.h"

void generate_keypair(EllipticCurve curve, int *private_key, Point *public_key);

#endif // KEYGEN_H


#ifndef KEYGEN_H
#define KEYGEN_H

#include <stdio.h>
#include "ec_crypto.h"
#include <time.h>

int generate_pvt_key();
ec_point generate_public_key(int pvt_key);
ec_point generate_shared_secret(int pvt_key, ec_point public_key);

#endif // KEYGEN_H

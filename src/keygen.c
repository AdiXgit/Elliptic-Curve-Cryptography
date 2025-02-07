//implementation of keygeneration and ecdh
#include "keygen.h"
int generate_pvt_key() {
    srand(time(0));
    return rand() % 100;
}

ec_point generate_public_key(int pvt_key){
    ec_point g = {2,2};
    return ecc_scalar_mult(g, pvt_key);
}

ec_point generate_shared_secret(int pvt_key,ec_point public_key){
    return ecc_scalar_mult(public_key,pvt_key);
}


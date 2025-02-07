#ifndef ECDSA_H
#define ECDSA_H

#include<stdint.h>
#include "ec_crypto.h"

extern ec_point G;
typedef struct{
    int pvt_key;
    ec_point public_key;
} ecdsa_keypair;

typedef struct {
    int r;int s;
} ecdsa_sign;

int hash_message(const char* msg);
ecdsa_keypair ecdsa_keygen();
ecdsa_sign ecdsa_sign_msg(int pvt_key, const char* msg);
int ecdsa_verify_msg(ec_point public_key, ecdsa_sign sign, const char* msg);

#endif

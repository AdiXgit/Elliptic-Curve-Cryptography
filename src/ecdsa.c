#include "ecdsa.h"
#include "field_math.h"

#include <string.h>

int hash_message(const char*msg){
    int hash = 0;
    for(size_t i = 0;i<strlen(msg);i++)
        hash = (hash+msg[i]) %PRIME;return hash;
}

//generating the key value pair
ecdsa_keypair ecdsa_keygen(){
    ecdsa_keypair keypair;
    keypair.pvt_key = 10023; //you can give any secure random private key
    //public key = private key * G(generator point)
    keypair.public_key = ecc_scalar_mult(G, keypair.pvt_key); //check later for the g value
    return keypair;
}

ecdsa_sign ecdsa_sign_msg(int pvt_key,const char*msg){
    int k = 17; //you can give any secure random number
    ec_point r = ecc_scalar_mult(G, k);;
    int r_x = r.x;
    int h = hash_message(msg);
    int s = mod_mul(mod_inv(k),mod_sub(h,mod_mul(r_x,pvt_key)));
    printf("Debug: k = %d\n", k);
    printf("Debug: r = (%d, %d)\n", r.x, r.y);
    printf("Debug: r_x = %d\n", r_x);
    printf("Debug: Hash = %d\n", h);
    printf("Debug: s = %d\n", s);


    ecdsa_sign sign = {r_x,s};
    return sign;
};




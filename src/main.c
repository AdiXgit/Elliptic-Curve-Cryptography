#include <stdio.h>
#include "ec_crypto.h"
#include "ecdsa.h"

int main() {
    printf("Elliptic Curve Cryptography Test\n");

    // 1️⃣ Generate Keypair
    ecdsa_keypair keypair = ecdsa_keygen();
    printf("Private Key: %d\n", keypair.pvt_key);
    printf("Public Key: (%d, %d)\n", keypair.public_key.x, keypair.public_key.y);

    // 2️⃣ Define a message
    const char* message = "Hello ECC!";
    printf("Message: %s\n", message);

    // 3️⃣ Sign the message
    ecdsa_sign signature = ecdsa_sign_msg(keypair.pvt_key, message);
    printf("Signature: (r = %d, s = %d)\n", signature.r, signature.s);

    // 4️⃣ Verify the signature
    int h = hash_message(message);
    int w = mod_inv(signature.s);
    int u1 = mod_mul(h, w);
    int u2 = mod_mul(signature.r, w);

    ec_point P1 = ecc_scalar_mult(G, u1);
    ec_point P2 = ecc_scalar_mult(keypair.public_key, u2);
    ec_point P = ecc_add(P1, P2);

    printf("Signature Valid: %s\n", (P.x == signature.r) ? "YES" : "NO");
    return 0;
}


#include "field_math.h"

// Modular addition
int mod_add(int a, int b) {
    return (a + b) % PRIME;
}

// Modular subtraction
int mod_sub(int a, int b) {
    return (a - b + PRIME) % PRIME;
}

// Modular multiplication
int mod_mul(int a, int b) {
    return (1LL * a * b) % PRIME;
}

// Modular exponentiation (a^b mod p)
int mod_exp(int base, int exp) {
    int result = 1;
    base = base % PRIME;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (1LL * result * base) % PRIME;
        }
        exp = exp >> 1;
        base = (1LL * base * base) % PRIME;
    }
    return result;
}

// Modular inverse
int mod_inv(int a) {
    int m = PRIME;  // Store PRIME in a mutable variable
    int t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;

        m = a % m;  // Use 'm' instead of modifying 'PRIME'
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    return (x1 + PRIME) % PRIME;
}

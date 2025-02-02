#include "ec_crypto.h"
#define curve_a 2
#define curve_b 9

ec_point ecc_add(ec_point p, ec_point q) {
    if (p.is_infinity) return q;
    if (q.is_infinity) return p;

    int lambda;
    if (p.x == q.x && p.y == q.y) {
        lambda = mod_mul(mod_add(mod_mul(3, mod_exp(p.x, 2)), curve_a), mod_inv(mod_mul(2, p.y)));
    } else {
        lambda = mod_mul(mod_sub(q.y, p.y), mod_inv(mod_sub(q.x, p.x)));
    }

    int xr = mod_sub(mod_exp(lambda, 2), mod_add(p.x, q.x));
    int yr = mod_sub(mod_mul(lambda, mod_sub(p.x, xr)), p.y);

    ec_point result = {xr, yr, 0};
    return result;
}

ec_point ecc_double(ec_point p) {
    if (p.is_infinity) return p;

    int lambda = mod_mul(mod_add(mod_mul(3, mod_exp(p.x, 2)), curve_a), mod_inv(mod_mul(2, p.y)));

    int xr = mod_sub(mod_exp(lambda, 2), mod_add(p.x, p.x));
    int yr = mod_sub(mod_mul(lambda, mod_sub(p.x, xr)), p.y);

    ec_point result = {xr, yr, 0};
    return result;
}

ec_point ecc_scalar_mult(ec_point p, int k) {
    ec_point result = {0, 0, 1};  // Infinity point
    ec_point temp = p;

    while (k > 0) {
        if (k & 1) {
            result = ecc_add(result, temp);
        }
        temp = ecc_double(temp);
        k >>= 1;
    }

    return result;
}

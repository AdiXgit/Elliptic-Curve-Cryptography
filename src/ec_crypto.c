#include "ec_crypto.h"

//the point acts as the identity element 
ec_point POINT_INFINITY = {0,0};

ec_point ecc_add(ec_point p, ec_point q){
    if(p.x == 0 && p.y == 0) return q;
    if(q.x == 0 && q.y == 0) return p;

    //checking if p and q are inverse (p+(-p) == infinity)
    if(p.x == q.x && p.y != q.y) return POINT_INFINITY;

    int lambda;
    if(p.x == q.x && p.y == q.y) return ecc_double(p);
    else(lambda = mod_mul(mod_sub(q.y,p.y),mod_inc(mod_sub(q.x,p.x),PRIME)));

    int xr = mod_sub(mod_sub(mod_exp(lambda, 2), p.x), q.x);
    int yr = mod_sub(mod_mul(lambda, mod_sub(p.x, xr)), q.y);

    ec_point R = {xr,yr};
    return R;
}

//this function used to double a point R = 2P
ec_point ecc_double(ec_point p){
    if(p.x == 0 && p.y == 0) return POINT_INFINITY;

    int lambda = mod_mul(mod_add(mod_mul(3,mod_exp(p.x,2)),curve_a),mod_inv(mod_mul(2,p.y)),PRIME);

    int xr = mod_sub(mod_exp(lambda,2),mod_mul(2,p.x));
    int yr = mod_sub(mod_mul(lambda,mod_sub(p.x,xr)),p.y);

    ec_point R = {xr,yr};
    return R; 
}

//scalar mul using double and add method 
ec_point ecc_scalar_mul(int k,ec_point p){
    ec_point R = POINT_INFINITY;
    ec_point temp = p;
    while(k>0){
        if(k & 1){
            R = ecc_add(R,temp);
        }
        temp = ecc_double(temp);
        k >>= 1;
    }
    return R;
}




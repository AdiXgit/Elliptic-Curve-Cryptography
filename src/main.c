//testing the ecc operations
#include<stdio.h>
#include "ec_crypto.h"

int main(){
    ec_point g = {2,2};
    printf("generator point g = (%d,%d)\n",g.x,g.y);

    //testing point addition
    ec_point p1 = ecc_add(g, g); // Assuming point_addition is a function in ec_crypto.h
    printf("2G = (%d,%d)\n", p1.x, p1.y);
    
    //testing scalar multiplication
    ec_point p2 = ecc_scalar_mul(3, g);
    printf("3G = (%d, %d)\n", p2.x, p2.y);

    return 0;
}


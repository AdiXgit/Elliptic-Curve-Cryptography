#include "ecc.h"
#include <stdio.h>
#include <stdlib.h>

// Function to check if a point is on the elliptic curve
int is_point_on_curve(EllipticCurve curve, Point point) {
    int left = (point.y * point.y) % curve.p;
    int right = (point.x * point.x * point.x + curve.a * point.x + curve.b) % curve.p;
    return left == right;
}

// Function to add two points on the elliptic curve
Point point_add(Point p1, Point p2, EllipticCurve curve) {
    if (!is_point_on_curve(curve, p1) || !is_point_on_curve(curve, p2)) {
        fprintf(stderr, "Error: One of the points is not on the curve.\n");
        exit(EXIT_FAILURE);
    }

    if (p1.x == 0 && p1.y == 0) return p2; // Identity point
    if (p2.x == 0 && p2.y == 0) return p1; // Identity point

    int m;
    if (p1.x == p2.x && p1.y == p2.y) {
        // Point doubling
        m = (3 * p1.x * p1.x + curve.a) * mod_inverse(2 * p1.y, curve.p) % curve.p;
    } else {
        m = (p2.y - p1.y) * mod_inverse(p2.x - p1.x, curve.p) % curve.p;
    }

    int x3 = (m * m - p1.x - p2.x) % curve.p;
    int y3 = (m * (p1.x - x3) - p1.y) % curve.p;

    Point result = { (x3 + curve.p) % curve.p, (y3 + curve.p) % curve.p };
    return result;
}

// Function to multiply a point by a scalar
Point point_multiply(Point p, int scalar, EllipticCurve curve) {
    Point result = {0, 0}; // Identity point
    Point addend = p;

    while (scalar) {
        if (scalar & 1) {
            result = point_add(result, addend, curve);
        }
        addend = point_add(addend, addend, curve); // Double the point
        scalar >>= 1;
    }
    return result;
}

// Function to compute modular inverse using Extended Euclidean Algorithm
int mod_inverse(int a, int p) {
    int m0 = p, t, q;
    int x0 = 0, x1 = 1;

    if (p == 1) return 0; // No modular inverse if modulus is 1

    while (a > 1) {
        q = a / p;  // Quotient
        t = p;

        p = a % p;  // Remainder
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) {
        x1 += m0; // Make sure the result is positive
    }

    return x1;
}

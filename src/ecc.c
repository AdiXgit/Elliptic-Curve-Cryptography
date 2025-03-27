#include "ecc.h"
#include <stdio.h>
#include <stdlib.h>

// Function to create a valid point
Point create_point(int x, int y) {
    return (Point){x, y, 0};  // Ensure it's a valid point (not infinity)
}

// Function to check if a point is on the elliptic curve
int is_point_on_curve(EllipticCurve curve, Point point) {
    if (point.is_infinity) return 1; // The point at infinity is valid

    int left = (point.y * point.y) % curve.p;
    int right = (point.x * point.x * point.x + curve.a * point.x + curve.b) % curve.p;

    // Ensure both sides are non-negative (handle modular arithmetic properly)
    left = (left + curve.p) % curve.p;
    right = (right + curve.p) % curve.p;

    printf("Checking point (%d, %d) on curve: Left = %d, Right = %d\n", 
            point.x, point.y, left, right);
    
    return left == right;
}


// Function to add two points on the elliptic curve
Point point_add(Point p1, Point p2, EllipticCurve curve) {
    if (p1.is_infinity) return p2;
    if (p2.is_infinity) return p1;

    if (!is_point_on_curve(curve, p1) || !is_point_on_curve(curve, p2)) {
        fprintf(stderr, "Error: One of the points is not on the curve. P1(%d,%d), P2(%d,%d)\n",
                p1.x, p1.y, p2.x, p2.y);
        exit(EXIT_FAILURE);
    }

    // If P1 == P2 and y == 0 → result should be "point at infinity"
    if (p1.x == p2.x && p1.y == p2.y && p1.y == 0) {
        return (Point){0, 0, 1};  // Return "point at infinity"
    }

    int m;
    if (p1.x == p2.x && p1.y == p2.y) {
        int denom = (2 * p1.y) % curve.p;
        if (denom == 0) return (Point){0, 0, 1}; // Correct infinity handling
        m = (3 * p1.x * p1.x + curve.a) * mod_inverse(denom, curve.p) % curve.p;
    } else {
        int denom = (p2.x - p1.x) % curve.p;
        if (denom == 0) return (Point){0, 0, 1}; // Correct infinity handling
        m = (p2.y - p1.y) * mod_inverse(denom, curve.p) % curve.p;
    }

    int x3 = (m * m - p1.x - p2.x) % curve.p;
    int y3 = (m * (p1.x - x3) - p1.y) % curve.p;

    return create_point((x3 + curve.p) % curve.p, (y3 + curve.p) % curve.p);
}


// Function to multiply a point by a scalar
Point point_multiply(Point p, int scalar, EllipticCurve curve) {
    Point result = {0, 0, 1}; // Correctly set as "point at infinity"
    Point addend = p;

    while (scalar) {
        if (scalar & 1) {
            result = point_add(result, addend, curve);
            printf("Multiplication step: result (%d, %d) [is_infinity=%d]\n", 
                   result.x, result.y, result.is_infinity);
        }
        addend = point_add(addend, addend, curve); // Double the point
        printf("Doubling step: addend (%d, %d) [is_infinity=%d]\n", 
               addend.x, addend.y, addend.is_infinity);
        scalar >>= 1;
    }
    return result;
}

// Function to compute modular inverse
int mod_inverse(int a, int p) {
    int m0 = p, t, q;
    int x0 = 0, x1 = 1;

    if (p == 1) return 0;

    while (a > 1) {
        q = a / p;
        t = p;
        p = a % p;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    return (x1 + m0) % m0;
}


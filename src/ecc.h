#ifndef ECC_H
#define ECC_H

typedef struct {
    int x;
    int y;
    int is_infinity;  // Flag to indicate "point at infinity"
} Point;

typedef struct {
    int a;
    int b;
    int p;
    Point G;  // Generator point
} EllipticCurve;

// Function prototypes
Point create_point(int x, int y);
int is_point_on_curve(EllipticCurve curve, Point point);
Point point_add(Point p1, Point p2, EllipticCurve curve);
Point point_multiply(Point p, int scalar, EllipticCurve curve);
int mod_inverse(int a, int p);

#endif

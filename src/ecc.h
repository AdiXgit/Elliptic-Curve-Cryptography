#ifndef ECC_H
#define ECC_H

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int a;
    int b;
    int p;  // Prime number
    Point G; // Generator point
} EllipticCurve;

int is_point_on_curve(EllipticCurve curve, Point point);
Point point_add(Point p1, Point p2, EllipticCurve curve);
Point point_multiply(Point p, int scalar, EllipticCurve curve);
int mod_inverse(int a, int p);

#endif // ECC_H

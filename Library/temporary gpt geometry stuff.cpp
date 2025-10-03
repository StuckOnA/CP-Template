#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    double x, y;

    // Constructors
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    // Operator overloads
    Point operator + (const Point &p) const { return {x + p.x, y + p.y}; }
    Point operator - (const Point &p) const { return {x - p.x, y - p.y}; }
    Point operator * (double k) const { return {x * k, y * k}; }
    Point operator / (double k) const { return {x / k, y / k}; }

    // Dot and cross products
    double dot(const Point &p) const { return x * p.x + y * p.y; }
    double cross(const Point &p) const { return x * p.y - y * p.x; }

    // Length
    double norm2() const { return x * x + y * y; }
    double norm()  const { return sqrt(norm2()); }

    // Normalize
    Point unit() const {
        double n = norm();
        return (n == 0 ? *this : *this / n);
    }

    // Rotation (counter-clockwise by theta)
    Point rotate(double theta) const {
        double c = cos(theta), s = sin(theta);
        return {x * c - y * s, x * s + y * c};
    }
};

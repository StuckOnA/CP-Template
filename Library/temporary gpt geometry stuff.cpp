#include <bits/stdc++.h>
using namespace std;

class Point {
public:
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    Point operator + (const Point &p) const { return {x + p.x, y + p.y}; }
    Point operator - (const Point &p) const { return {x - p.x, y - p.y}; }
    Point operator * (double k) const { return {x * k, y * k}; }
    Point operator / (double k) const { return {x / k, y / k}; }

    double dot(const Point &p) const { return x * p.x + y * p.y; }
    double cross(const Point &p) const { return x * p.y - y * p.x; }

    double norm2() const { return x * x + y * y; }
    double norm()  const { return sqrt(norm2()); }

    double angle() const {
        return atan2(y, x);
    }

    Point unit() const {
        double n = norm();
        return (n == 0 ? *this : *this / n);
    }

    Point rotate(double theta) const {
        double c = cos(theta), s = sin(theta);
        return {x * c - y * s, x * s + y * c};
    }
};

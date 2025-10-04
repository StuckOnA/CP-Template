class point {
public:
    double x, y;

    point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    point operator + (const point &p) const { return {x + p.x, y + p.y}; }
    point operator - (const point &p) const { return {x - p.x, y - p.y}; }
    point operator * (double k) const { return {x * k, y * k}; }
    point operator / (double k) const { return {x / k, y / k}; }

    double dot(const point &p) const { return x * p.x + y * p.y; }
    double cross(const point &p) const { return x * p.y - y * p.x; }

    double norm2() const { return x * x + y * y; }
    double norm()  const { return sqrt(norm2()); }

    double angle() const {
        return atan2(y, x);
    }

    point unit() const {
        double n = norm();
        return (n == 0 ? *this : *this / n);
    }

    point rotate(double theta) const {
        double c = cos(theta), s = sin(theta);
        return {x * c - y * s, x * s + y * c};
    }

    friend istream& operator>>(istream &in, point &p) {
        return in >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream &out, const point &p) {
        out << fixed << setprecision(6);
        return out << p.x << " " << p.y << endl;
    }
};

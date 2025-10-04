const double PI = acos(-1.0);

class point {
public:
    double x, y;

    point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    point operator + (const point &p) const { return {x + p.x, y + p.y}; }
    point operator - (const point &p) const { return {x - p.x, y - p.y}; }
    point operator * (double k) const { return {x * k, y * k}; }
    point operator / (double k) const { return {x / k, y / k}; }

    double norm2() const { return x * x + y * y; }
    double norm()  const { return sqrt(norm2()); }

    double angle() const {
        return atan2(y, x);
        //return fmod(atan2(y, x) + 2 * M_PI, 2 * M_PI);
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

inline double dot(const point &a, const point &b) {
    return a.x * b.x + a.y * b.y;
}

inline double cross(const point &a, const point &b) {
    return a.x * b.y - a.y * b.x;
}

double angle_between(const point &a, const point &b) {
    return atan2(fabs(cross(a, b)), dot(a, b));
}

struct F {
    double x;
    F(double _x) : x(_x) {}
};

ostream& operator<<(ostream& os, const F& f) {
    os << std::format("{:.6f}", f.x);
    return os;
}

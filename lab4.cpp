#include <iostream>

using namespace std;
typedef long long ll;

struct vector2 {
    double x, y;

    vector2() {}

    vector2(double x, double y) {
        this->x = x;
        this->y = y;
    }

    vector2 operator+(const vector2 &v2) const {
        return {x + v2.x, y + v2.y};
    }

    vector2 operator-(const vector2 &v2) const {
        return {x - v2.x, y - v2.y};
    }

    double operator*(const vector2 &v2) const {
        return x * v2.x + y * v2.y;
    }

    double operator%(const vector2 &v2) const {
        return x * v2.y - y * v2.x;
    }


};

istream &operator>>(istream &in, vector2 &v) {
    in >> v.x >> v.y;
    return in;
}

ostream &operator<<(ostream &out, vector2 v) {
    out << "x: " << v.x << ", y: " << v.y;
    return out;
}

int main() {
    vector2 v1, v2;
    //1
    cin >> v1 >> v2;
    //2
    cout << v1 << "; " << v2 << "\n";
    //3
    vector2 sum = v1 + v2;
    cout << sum << "\n";
    //4
    vector2 sub = v1 - v2;
    cout << sub << "\n";
    //5
    double scalarProduct = v1 * v2;
    cout << scalarProduct << "\n";
    //6
    double crossProduct = v1 % v2;
    cout << crossProduct << "\n";
    return 0;
}


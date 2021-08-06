#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef unsigned int uint;

//Task 1
bool is_correct_triangle(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) return false;
    double sides[3] = {a, b, c};
    sort(sides, sides + 3);
    return sides[2] < sides[0] + sides[1];
}

//Task 2
double area_of_triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = sqrt(abs(x1 - x2)*abs(x1 - x2) + abs(y1 - y2)*abs(y1 - y2));
    double b = sqrt(abs(x1 - x3)*abs(x1 - x3) + abs(y1 - y3)*abs(y1 - y3));
    double c = sqrt(abs(x3 - x2)*abs(x3 - x2) + abs(y3 - y2)*abs(y3 - y2));
    if (!is_correct_triangle(a, b, c)) return -1;
    double p = (a + b + c) / 2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

//Task 3
uint gcd(uint a, uint b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}


int main() {
    //1
    double a, b, c;
    cin >> a >> b >> c;
    cout << is_correct_triangle(a, b, c) << "\n";
    //2
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << area_of_triangle(x1, y1, x2, y2, x3, y3);
    //3
    uint x, y;
    cin >> x >> y;
    cout << gcd(x, y);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    double a, b, x;
    cin >> a >> b >> x;

    double rad;
    if (x / a > (a * b / 2)) {
        double h = 2 * (a*b - (x/a)) / a;
        rad = atan2(h , a);
    }else {
        double h = 2 * x / (a * b);
        rad = atan2(b,h);
    }


    double deg = rad / (2 * M_PI) * 360;

    printf("%.10f", deg);

}

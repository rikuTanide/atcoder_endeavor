#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

struct V {
    double x, y;

    V(double x = 0, double y = 0) : x(x), y(y) {

    }

    V &operator+=(const V &v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    double dot(const V &v) const {
        return x * v.x + y * v.x;
    }

    double cross(const V &v) const {
        return x * v.y - v.x * y;
    }

    int ort() const {
        if (y > 0) return x > 0 ? 1 : 2;
        else return x > 0 ? 4 : 3;
    }

    bool operator<(const V &v) const {
        int o = ort(), vo = v.ort();
        if (o != vo)return o < vo;
        return cross(v) > 0;
    }

    double norm2() const { return x * x + y * y; }

    double norm() const { return sqrt(norm2()); }

    V &operator+(const V &v) const { return V(*this) += v; }
};

istream &operator>>(istream &i, V &v) {
    i >> v.x >> v.y;
    return i;
}

ostream &operator>>(ostream &o, const V &v) {
    o << "(" << v.x << "," << v.y << ")";
    return o;
}

int main() {

    int n;
    cin >> n;
    vector<V> v(n);

    rep(i, n) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    double ans = 0;
    rep(l, n) {
        int r = l;
        V now;
        rep(i, n) {
            now += v[r];
            ans = max(ans, now.norm());
            r = (r + 1) % n;
        }

    }
    printf("%.12f\n", ans);


}

#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Day {
    int month, day;

    Day tomorrow() {
        int ma = get_max_day();
        if (ma == day) {
            return {month + 1, 1};
        } else {
            return {month, day + 1};
        }
    }

    int get_max_day() {
        if (
                month == 1 ||
                month == 3 ||
                month == 5 ||
                month == 7 ||
                month == 8 ||
                month == 10 ||
                month == 12
                ) {
            return 31;
        } else if (
                month == 4 ||
                month == 6 ||
                month == 9 ||
                month == 11
                ) {
            return 30;
        } else {
            return 29;
        }
    }

};

int main() {
    int ma, da, mb, db;
    cin >> ma >> da >> mb >> db;

    Day now = {ma, da};

    int count = 0;
    while (true) {
        if (now.month == mb && now.day == db) break;
        now = now.tomorrow();
        count++;
    }
    cout << count << endl;


}

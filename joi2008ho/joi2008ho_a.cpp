#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

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


int main() {
    int n;
    cin >> n;

    vector<char> color;
    vector<int> count;

    auto turn = [&](char c) {
        if (c == 'B') return 'W';
        return 'B';
    };

    rep(i, n) {
        int a;
        cin >> a;

        char c = a == 1 ? 'B' : 'W';

        if (i == 0) {
            color.push_back(c);
            count.push_back(1);
        } else if (i % 2 == 0) {

            if (color.back() == c) {
                count.back()++;
            } else {
                color.push_back(c);
                count.push_back(1);
            }
        } else {
            if (color.back() == c) {
                count.back()++;
            } else {
                color.back() = turn(color.back());
                count.back()++;

                if (color.size() >= 2) {
                    if (color[color.size() - 1] == color[color.size() - 2]) {
                        count[count.size() - 2] += count[count.size() - 1];
                        color.pop_back();
                        count.pop_back();
                    }
                }

            }
        }
    }

    ll ans = 0;
    rep(i, color.size()) {
        if (color[i] == 'W') ans += count[i];
    }
    cout << ans << endl;

}
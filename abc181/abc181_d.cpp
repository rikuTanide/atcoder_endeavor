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

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    string s;
    cin >> s;


    vector<int> count(10, 0);
    for (char c : s) {
        int i = c - '0';
        count[i]++;
    }
    bool ok = [&] {


        if (s.size() == 2) {
            int i = s[0] - '0';
            int j = s[1] - '0';
            if ((i * 10 + j) % 8 == 0) return true;
            if ((j * 10 + i) % 8 == 0) return true;

            return false;
        }

        if (s.size() == 1) {
            return s == "8";
        }


        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = 1; k <= 9; k++) {
                    vector<int> tmp = count;
                    tmp[i]--;
                    tmp[j]--;
                    tmp[k]--;

                    if (tmp[i] < 0) continue;
                    if (tmp[j] < 0) continue;
                    if (tmp[k] < 0) continue;
                    ll x = i * 100 + j * 10 + k;
                    if (x % 8 == 0) return true;

                }
            }
        }
        return false;
    }();

    cout << (ok ? "Yes" : "No") << endl;
}

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

    int n;
    cin >> n;

    vector<vector<double>> dots = {
            {-0.382803257217051312526823105144, -0.382803257217051312526823105144},
            {-0.148409771651153937580469315432, -0.382803257217051312526823105144},
            {0.148409771651153937580469315432,  -0.382803257217051312526823105144},
            {0.382803257217051312526823105144,  -0.382803257217051312526823105144},
            {0.000000000000000000000000000000,  -0.201378766714300041594758852417},
            {-0.382803257217051312526823105144, -0.148409771651153937580469315432},
            {0.382803257217051312526823105144,  -0.148409771651153937580469315432},
            {-0.173215633049774766600908965070, -0.043465339346972228784768079357},
            {0.173215633049774766600908965070,  -0.043465339346972228784768079357},
            {-0.382803257217051312526823105144, 0.085983713914743437365884474280},
            {0.382803257217051312526823105144,  0.085983713914743437365884474280},
            {0.000000000000000000000000000000,  0.114448088020355584025222693703},
            {-0.201378766714300041594758852417, 0.234393485565897374946353789712},
            {0.201378766714300041594758852417,  0.234393485565897374946353789712},
            {0.000000000002334945869920137344,  0.367491125623834139333057329567},
            {-0.382803257217051312526823105144, 0.382803257217051312526823105144},
            {0.382803257217051312526823105144,  0.382803257217051312526823105144},
    };

    ll dig = 1e8;

    for (auto e : dots) {
        cout << ll((e[0] + 0.5) * dig) << ' ' << ll((e[1] + 0.5) * dig) << endl;
//        cout << e[0] + 0.5 << ' ' << e[1] + 0.5 << endl;
//        cout << e[0] << ' ' << e[1] << endl;
    }

}


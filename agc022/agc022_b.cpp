#include <bits/stdc++.h>
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

void print(vector<ll> &v) {
    for (ll l : v) cout << l << endl;
}

int main() {
    ll n;
    cin >> n;

    if (n == 3) {
        cout << "2 5 63" << endl;
        return 0;
    }

    if (n == 4) {
        cout << "2 5 63 20" << endl;
        return 0;
    }

    if (n == 5) {
        cout << "2 5 20 30 63" << endl;
        return 0;
    }

    vector<ll> tmp;

    for (ll a = 2; tmp.size() < n; a++) {
        if (a % 2 == 0 || a % 3 == 0) tmp.push_back(a);
    }

    ll sum = accumulate(tmp.begin(), tmp.end(), 0ll);



//    if (sum % 6 == 0) {
//        print(tmp);
//        ret();
//    }


    ll add = sum % 6;

    if (add == 5) {
        tmp.erase(find(tmp.begin(), tmp.end(), 6 + 3));

        tmp.push_back(30000 - 2);

        print(tmp);
        ret();
    }

    if (add != 0) {
        ll fp = 6 + add;

        tmp.erase(find(tmp.begin(), tmp.end(), fp));
        tmp.push_back(30000);
    }
    print(tmp);


//    if (sum % 6 == 1) {
//
//        30000
//        ret();
//    }
//
//    __throw_runtime_error("konai");


}

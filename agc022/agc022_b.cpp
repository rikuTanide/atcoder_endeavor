#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
typedef pair<ll, ll> P;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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


int main() {
    int n;
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

    vector<ll> a;
    map<ll, vector<ll>> unused;

    rep(i, 30000 + 1) {
        if (i == 0) continue;
        if (i % 6 == 1 || i % 6 == 5) continue;
        if (a.size() < n) {
            a.push_back(i);
            continue;
        }
        unused[i % 6].push_back(i);
    }
    ll sum_v = accumulate(a.begin(), a.end(), 0ll);
    if (sum_v % 6 == 2) {
        a.erase(find(a.begin(), a.end(), 8));
        a.push_back(unused[0].front());
    }
    if (sum_v % 6 == 3) {
        a.erase(find(a.begin(), a.end(), 9));
        a.push_back(unused[0].front());
    }
    if (sum_v % 6 == 5) {
        a.erase(find(a.begin(), a.end(), 9));
        a.push_back(unused[4].front());
    }

    for (ll i : a) cout << i << ' ';
    cout << endl;
}




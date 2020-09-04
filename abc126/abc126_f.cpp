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

void sample() {

    rep(m, 4) {
        vector<ll> v;
        rep(i, 1 << m) v.push_back(i);
        rep(i, 1 << m) v.push_back(i);
        int n = v.size();
        vector<int> arr(n);
        rep(i, n) arr[i] = i;

        do {
            set<ll> xx;
            rep(i, 1 << m) {
                vector<int> k;
                rep(j, n) if (v[arr[j]] == i) k.push_back(j);

                ll x = 0;
                for (int j = k.front(); j <= k.back(); j++) {
                    x ^= v[arr[j]];
                }
                xx.insert(x);
            }
            if (xx.size() == 1 && (*xx.begin()) != 0) {

                cout << *xx.begin() << ':';
                rep(i, n) cout << v[arr[i]] << ' ';
                cout << endl;

            }
        } while (std::next_permutation(arr.begin(), arr.end()));

    }

}

int main() {
//    sample();
//    ret();
    int n;
    ll k;
    cin >> n >> k;

    if (k == 0) {
        vector<int> ans;
        rep(i, 1 << n) ans.push_back(i), ans.push_back(i);
        for (int i : ans) cout << i << ' ';
        ret();
    }

    if (n == 1 && k == 1) {
        cout << -1 << endl;
        ret();
    }

    if (k >= (1 << n)) {
        cout << -1 << endl;
        ret();
    }


    vector<int> ans;
    rep(i, k) ans.push_back(i);
    ans.push_back(k);
    rep(i, k) ans.push_back(k - i - 1);
    for (int i = (1 << n) - 1; i > k; i--) ans.push_back(i);
    ans.push_back(k);
    for (int i = k + 1; i < (1 << n); i++) ans.push_back(i);

    for (int i : ans) cout << i << ' ';


}

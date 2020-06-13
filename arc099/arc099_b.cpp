#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


ll f(ll n) {
    ll res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}


vector<ll> get_ks(vector<ll> &candidates) {
    int n = candidates.size();
    vector<ll> ans;


    for (ll i = 0; i < n; i++) {
        bool b = [&] {
            for (ll j = i + 1; j < n; j++) {
                ll a = candidates[i], b = candidates[j];
                if (a * f(b) > b * f(a)) return false;
            }
            return true;
        }();
        if (b) ans.push_back(candidates[i]);
    }

    return ans;

}

int main() {
    vector<ll> res;
    ll base = 1;

    for (int i = 0; i < 15; ++i) {
        for (int j = 1; j < 150; ++j) {
            res.push_back(base * (j + 1) - 1);
        }
        base *= 10;
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    vector<ll> ks = get_ks(res);

    ll K;
    cin >> K;
    for (ll i = 0; i < K; ++i) {
        cout << ks[i] << endl;
    }
}
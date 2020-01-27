#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct MP {
    int n;
    vector<int> a;
    vector<int> t;

    MP() {}

    MP(const vector<int> &t) : t(t) {
        n = t.size();
        a = vector<int>(n + 1);
        a[0] = -1;
        int j = -1;
        for (int i = 0; i < n; i++) {
            while (j != -1 && t[j] != t[i]) j = a[j];
            j++;
            a[i + 1] = j;
        }
    }

    int operator[](int i) {
        return a[i];
    }

    vector<int> findAll(const vector<int> &s) {
        vector<int> res;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j != -1 && t[j] != s[i]) j = a[j];
            j++;
            if (j == n) {
                res.push_back(i - j + 1);
                j = a[j];
            }
        }
        return res;
    }
};

vector<int> f(vector<int> &a) {
    int n = a.size();
    vector<int> res(n);
    rep(i, n) res[i] = a[i] ^ a[(i + 1) % n];
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> xa = f(a);
    vector<int> xb = f(b);
    xb.insert(xb.end(), xb.begin(), xb.end());
    MP mp(xa);
    vector<int> res = mp.findAll(xb);
    vector<int> ks;
    for (int p : res) ks.push_back(n - p);
    sort(ks.begin(), ks.end());
    for (int k : ks) {
        if (k >= n)continue;
        int x = a[k] ^b[0];
        printf("%d %d\n", k, x);
    }


}

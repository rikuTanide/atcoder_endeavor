#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

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
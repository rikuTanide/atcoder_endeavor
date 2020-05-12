#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {

    string s;
    cin >> s;
    rep(i, 1 << 4) {
        vector<int> v;
        rep(j, 4)if ((i >> j) & 1) v.push_back(j);

        string u = "AKIHABARA";
        for (int j : v) {
            if (j == 0) u[0] = ' ';
            if (j == 1) u[4] = ' ';
            if (j == 2) u[6] = ' ';
            if (j == 3) u[8] = ' ';
        }
        string t = "";
        rep(i, u.size())if (u[i] != ' ') t.push_back(u[i]);
        if (s == t) {
            cout << "YES" << endl;
            ret();
        }
    }
    cout << "NO" << endl;
}

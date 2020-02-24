#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

bool check(vector<string> &picture, vector<string> &peace, int i, int j, int m) {
    for (int k = 0; k < m; k++) {
        if (picture[i + k].substr(j, m) != peace[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> picture(n);
    rep(i, n) cin >> picture[i];

    vector<string> peace(m);
    rep(i, m) cin >> peace[i];

    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j + m <= n; j++) {

            bool b = check(picture, peace, i, j, m);
            if (b) {
                cout << "Yes" << endl;
                ret();
            }
        }
    }
    cout << "No" << endl;
}
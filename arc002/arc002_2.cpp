#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

int dmax(int y, int m) {
    if (m == 2) {
        if (y % 400 == 0) {
            return 29;
        } else if (y % 100 == 0) {
            return 28;
        } else if (y % 4 == 0) {
            return 29;
        } else {
            return 28;
        }
    }
    switch (y) {
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

template<typename ... Args>
std::string format(const std::string &fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
    return std::string(&buf[0], &buf[0] + len);
}

string ymd(int y, int m, int d) {
    return format("%d/%02d/%02d", y, m, d);
}

bool check(int y, int m, int d) {
    if (y % m != 0) return false;
    y /= m;
    if (y % d != 0) return false;
    return true;
}

vector<string> w() {
    vector<string> res;
    for (int y = 1000; y <= 2999; y++) {
        for (int m = 1; m <= 12; m++) {
            for (int d = 1; d <= dmax(y, m); d++) {
                if (check(y, m, d)) res.push_back(ymd(y, m, d));
            }
        }
    }
    return res;
}

int main() {
    auto ymds = w();

    string s;
    cin >> s;

    string ans = *lower_bound(ymds.begin(), ymds.end(), s);

    cout << ans << endl;

}
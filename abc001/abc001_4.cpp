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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int get_time() {
    char h1, h2, m1, m2;
    cin >> h1 >> h2 >> m1 >> m2;
    int hour = (h1 - '0') * 10 + (h2 - '0');
    int minute = (m1 - '0') * 10 + (m2 - '0');
    return hour * 60 + minute;
}

int round_down(int i) {
    int m = i % 10;
    int j = i / 10 * 10;
    if (m <= 4) return j + 0;
    else if (m <= 9) return j + 5;
    throw "konai";
}

int round_up(int i) {
    int m = i % 10;
    int j = i / 10 * 10;
    if (m == 0) return j + 0;
    else if (m <= 5) return j + 5;
    else if (m <= 9) return j + 10;
    throw "konai";
}

int main() {
    int n;
    cin >> n;

    vector<int> imos(60 * 30, 0);

    rep(i, n) {
        int start = round_down(get_time());
        char c;
        cin >> c;
        assert(c == '-');
        int end = round_up(get_time());
        imos[start]++;
        imos[end + 1]--;
    }
    rep(i, 60 * 30) {
        if (i == 0)continue;
        imos[i] += imos[i - 1];
    }

    auto is_start = [&](int i) {
        if (i == 0 && imos[i] == 1) return true;
        if (i == 0) return false;
        return imos[i - 1] == 0 && imos[i] >= 1;
    };

    auto is_end = [&](int i) {
        return imos[i] >= 1 && imos[i + 1] == 0;
    };

//    rep(j, 60 * 30) {
//        int i = imos[j];
//        cout << i;
//        if (j % 60 == 0) cout << endl;
//    }
//
    vector<P> ans;
    rep(i, 60 * 29) {
        if (is_start(i)) {
            ans.push_back(P(i, -1));
        } else if (is_end(i)) {
            ans.back().second = i;
        }
    }
    for (P p : ans) {
        printf("%02lld%02lld-%02lld%02lld\n", p.first / 60, p.first % 60, p.second / 60, p.second % 60);
    }
}


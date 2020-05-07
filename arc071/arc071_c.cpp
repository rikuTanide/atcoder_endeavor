#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
const int mod = 1000000007;

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


int cnt(CumulativeSum &s, int a, int b) {
    return s.getSectionSum(a, b) % 3;
}

int main() {
    string s, t;
    cin >> s >> t;

    CumulativeSum ssum(s.size()), tsum(t.size());
    rep(i, s.size()) {
        if (s[i] == 'A') ssum.set(i, 1);
        else if (s[i] == 'B') ssum.set(i, 2);
    }
    rep(i, t.size()) {
        if (t[i] == 'A') tsum.set(i, 1);
        else if (t[i] == 'B') tsum.set(i, 2);
    }
    ssum.calculate();
    tsum.calculate();

    int q;
    cin >> q;

    rep(i, q) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        a--;
        b--;
        c--;
        d--;

        if (cnt(ssum, a, b) == cnt(tsum, c, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

}

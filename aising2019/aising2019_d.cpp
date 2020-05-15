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

// https://drken1215.hatenablog.com/entry/2019/01/13/033500
int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> cards(n);
    rep(i, n) cin >> cards[i];

    reverse(cards.begin(), cards.end());

    CumulativeSum sum(n), evensum(n);
    rep(i, n) sum.set(i, cards[i]);
    rep(i, n) if (i % 2 == 0)evensum.set(i, cards[i]);
    sum.calculate();
    evensum.calculate();

    vector<ll> ths, vals;
    rep(i, (n - 1) / 2) {
        ll th = (cards[i + 1] + cards[i * 2 + 2]) / 2 + 1;
        ll val = sum.getSum(i) + (evensum.getSum(n) - evensum.getSum(i * 2 + 1));
        ths.push_back(th);
        vals.push_back(val);
    }

    reverse(ths.begin(), ths.end());
    reverse(vals.begin(), vals.end());

    rep(_, q) {
        ll x;
        cin >> x;
        auto it = upper_bound(ths.begin(), ths.end(), x);
        int i = distance(ths.begin(), it);

        if (i == 0) cout << sum.getSum((n + 1) / 2 - 1) << endl;
        else cout << vals[i - 1] << endl;

    }


}
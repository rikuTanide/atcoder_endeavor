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

typedef pair<ll, double> P;

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

class CumulativeSumZero {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSumZero(int n) {
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
            sums[i] = getSum(i - 1) + max(numbers[i], 0ll);
        }
    }

};


int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> scores(n);
    rep(i, n) cin >> scores[i];

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, scores[i]);
    cs.calculate();

    CumulativeSumZero csz(n);
    rep(i, n) csz.set(i, scores[i]);
    csz.calculate();

//    rep(i, n) {
//        if (i != 0) {
//            cout << 0 << ' ' << i - 1 << ' ';
//        }
//        cout << i << ' ' << min(i + k - 1, n) << ' ';
//        if (i + k < n) {
//            cout << i + k << ' ' << n;
//        }
//        cout << endl;
//    }

    ll ans = 0;
    rep(i, n) {
        if (i + k > n) continue;
        ll now = 0;
        if (i != 0) {
//            cout << 0 << ' ' << i - 1 << ' ';
            now += csz.getSectionSum(0, i - 1);
        }
//        cout << i << ' ' << min(i + k - 1, n) << ' ';
        now += max(cs.getSectionSum(i, min(i + k - 1, n)), 0ll);
        if (i + k < n) {
//            cout << i + k << ' ' << n;
            now += csz.getSectionSum(i + k, n);
        }
        cmax(ans, now);
    }
    cout << ans << endl;

}

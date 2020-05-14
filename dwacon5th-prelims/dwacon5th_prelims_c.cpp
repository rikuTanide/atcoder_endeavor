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
        if (start > numbers.size()) return 0;
        cmin(end, int(numbers.size() - 1));
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};


int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    CumulativeSum ds(n), ms(n), cs(n);
    rep(i, n) {
        char c = s[i];
        if (c == 'D') ds.set(i, 1);
        if (c == 'M') ms.set(i, 1);
        if (c == 'C') cs.set(i, 1);
    }
    ds.calculate();
    ms.calculate();
    cs.calculate();

    CumulativeSum mcs(n);
    rep(i, n) {
        if (s[i] != 'M') continue;
        mcs.set(i, cs.getSectionSum(i + 1, n - 1));
    }
    mcs.calculate();

    int q;
    cin >> q;

    rep(qi, q) {
        int k;
        cin >> k;
        ll all = 0;
        rep(i, n) {
            if (s[i] != 'M') continue;
            ll d = ds.getSectionSum(0, i - 1);
            ll c = cs.getSectionSum(i + 1, n - 1);

            ll now = d * c;
            all += now;
        }

        ll sub_1 = 0;
        rep(i, n) {
            if (s[i] != 'D') continue;
//            ll m = ds.getSectionSum(i + 1, i + k);
            ll m = ms.getSectionSum(i, i + k);
//            ll c = cs.getSectionSum(i + k + 1, n - 1);
            ll c = cs.getSectionSum(i + k , n - 1);
            ll now = m * c;
            sub_1 += now;
        }

        ll sub_2 = 0;
        rep(i, n) {
            if (s[i] != 'D') continue;
//            ll now = mcs.getSectionSum(i + k + 1, n - 1);
            ll now = mcs.getSectionSum(i + k + 1, n - 1);
            sub_2 += now;
        }

        ll ans = all - sub_1 - sub_2;

        cout << ans << endl;
    }
}
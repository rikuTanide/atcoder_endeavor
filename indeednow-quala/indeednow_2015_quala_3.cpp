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

class CumulativeSum {
    vector<ll> numbers;

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
        if (i == sums.size()) return 0;
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

    vector<ll> sums;

};


int main() {

    int n;
    cin >> n;

    vector<ll> scores(n);
    rep(i, n) cin >> scores[i];

    ll ma = *max_element(scores.begin(), scores.end()) + 1;
    vector<ll> counts(ma, 0);
    for (ll s : scores) counts[s]++;

    CumulativeSum cs(ma);
    rep(i, ma) {
        cs.set(i, counts[i]);
    }
    cs.calculate();

    int q;
    cin >> q;

    rep(i, q) {
        int k;
        cin >> k;
        ll target = n - k;
        if (target <= counts[0]) {
            cout << 0 << endl;
            continue;
        }
        auto it = lower_bound(cs.sums.begin(), cs.sums.end(), target);
        int index = distance(cs.sums.begin(), it);
        cout << index + 1 << endl;

    }

}


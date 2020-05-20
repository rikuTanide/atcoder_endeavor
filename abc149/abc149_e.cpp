#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

int main() {
    int n, m;
    cin >> n >> m;

    vector<ll> people(n);
    rep(i, n) cin >> people[i];

    sort(people.begin(), people.end());


    ll floor = -1, ceil = INF;

    auto count_over = [&](ll mid) {
        ll sum = 0;
        for (ll p : people) {
            ll k = mid - p;
            auto it = lower_bound(people.begin(), people.end(), k);
            int c = distance(it, people.end());
            sum += c;
        }
        return sum;
    };

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll c = count_over(mid);
        if (m < c) floor = mid;
        else ceil = mid;
    }


    auto count_over_h = [&](ll over) {
        CumulativeSum cs(n);
        rep(i, n) cs.set(i, people[i]);
        cs.calculate();

        ll sum = 0;
        for (ll p : people) {
            ll k = over - p;
            auto it = lower_bound(people.begin(), people.end(), k);
            int c = distance(it, people.end());
            ll lh = c * p;
            ll rh = cs.getSectionSum(n - c, n);
            ll now = lh + rh;
            sum += now;
        }
        return sum;
    };

    ll over = count_over(ceil);
    ll ext = m - over;
    ll eq_h = floor * ext;
    ll over_h = count_over_h(ceil);

    ll ans = eq_h + over_h;
    cout << ans << endl;

}
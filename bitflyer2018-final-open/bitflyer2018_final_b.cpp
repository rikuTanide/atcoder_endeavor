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

    void build() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

struct RangeCount {
    int upper, r_equal, between, l_equal, lower;

    friend std::ostream &operator<<(std::ostream &out, const RangeCount &o) {
        cout << endl;
        cout << "upper" << ' ' << o.upper << endl;
        cout << "r_equal" << ' ' << o.r_equal << endl;
        cout << "between" << ' ' << o.between << endl;
        cout << "l_equal" << ' ' << o.l_equal << endl;
        cout << "lower" << ' ' << o.lower << endl;
        return out;
    }
};


// startは含む
// endは含まない
RangeCount range_count(vector<ll>::iterator begin, vector<ll>::iterator end, ll l, ll r) {
    if (l > r) return RangeCount{0, 0, 0, 0, 0};
    if (begin >= end) return RangeCount{0, 0, 0, 0, 0};

    if (l == r) {
        RangeCount rc;
        auto it = std::equal_range(begin, end, r);

        rc.upper = distance(it.second, end);
        rc.r_equal = distance(it.first, it.second);
        rc.between = 0;
        rc.l_equal = rc.r_equal;
        rc.lower = distance(begin, it.first);

        return rc;
    }

    RangeCount rc;
    auto it_r = std::equal_range(begin, end, r);
    auto it_l = std::equal_range(begin, end, l);

    auto it_ru = it_r.second;
    auto it_rl = it_r.first;
    rc.upper = distance(it_ru, end);
    rc.r_equal = distance(it_rl, it_ru);
    auto it_lu = it_l.second;
    auto it_ll = it_l.first;
    rc.between = distance(it_lu, it_rl);
    rc.l_equal = distance(it_ll, it_lu);
    rc.lower = distance(begin, it_ll);

    return rc;

}


int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> places(n);
    rep(i, n) cin >> places[i];

    CumulativeSum cs(n);
    rep(i, n) cs.set(i, places[i]);
    cs.build();

    auto sum = [&](ll a, ll b) -> ll {
        auto l = lower_bound(places.begin(), places.end(), a);
        auto r = lower_bound(places.begin(), places.end(), b);
        if (l == r) return 0;
        r--;
        int li = distance(places.begin(), l);
        int ri = distance(places.begin(), r);
        return cs.getSectionSum(li, ri);
    };

    rep(i, q) {
        ll c, d;
        cin >> c >> d;


        auto l = range_count(places.begin(), places.end(), c - d, c);
        auto r = range_count(places.begin(), places.end(), c, c + d);

        int la = l.lower;
        int ra = r.upper;

        ll a = sum(c - d, c);
        ll b = sum(c + 1, c + d + 1);

        ll ans_ll = la * d;
        ll ans_l = c * (l.l_equal + l.between) - a;
        ll ans_r = b - (r.between + r.r_equal) * c;
        ll ans_rr = ra * d;

        ll ans = ans_ll + ans_l + ans_r + ans_rr;
        cout << ans << endl;

    }

}

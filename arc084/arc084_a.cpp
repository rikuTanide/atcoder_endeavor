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
        auto it_u = upper_bound(begin, end, r);
        auto it_l = lower_bound(begin, end, r);

        rc.upper = distance(it_u, end);
        rc.r_equal = distance(it_l, it_u);
        rc.between = 0;
        rc.l_equal = rc.r_equal;
        rc.lower = distance(begin, it_l);

        return rc;
    }

    RangeCount rc;
    auto it_ru = upper_bound(begin, end, r);
    auto it_rl = lower_bound(begin, end, r);
    rc.upper = distance(it_ru, end);
    rc.r_equal = distance(it_rl, it_ru);
    auto it_lu = upper_bound(begin, end, l);
    auto it_ll = lower_bound(begin, end, l);
    rc.between = distance(it_lu, it_rl);
    rc.l_equal = distance(it_ll, it_lu);
    rc.lower = distance(begin, it_ll);

    return rc;

}


int main() {
    int n;
    cin >> n;
    vector<vector<ll>> piece(3, vector<ll>(n));
    rep(i, 3) rep(j, n) cin >> piece[i][j];
    rep(i, 3) sort(piece[i].begin(), piece[i].end());


    ll ans = 0;
    for (ll b : piece[1]) {
        RangeCount arc = range_count(piece[0].begin(), piece[0].end(), b, b);
        RangeCount crc = range_count(piece[2].begin(), piece[2].end(), b, b);

        ll l = arc.lower;
        ll u = crc.upper;

        ans += l * u;
    }

    cout << ans << endl;
}
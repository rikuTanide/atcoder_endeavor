#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct RangeCount {
    ll upper, r_equal, between, l_equal, lower;

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


ll check_bit(ll a, vector<ll> &bs, ll j) {
    ll t = 1 << j;

    ll t1 = t - a;
    ll t2 = 2 * t - a;
    ll t3 = 3 * t - a;
    ll t4 = 4 * t - a;

    auto rc1 = range_count(bs.begin(), bs.end(), t1, t2);
    auto rc2 = range_count(bs.begin(), bs.end(), t3, t4);

    ll now = rc1.between + rc1.l_equal + rc2.between + rc2.l_equal;

    return now;

}

vector<ll> md(vector<ll> &a, ll j) {
    vector<ll> ans(a.size());
    rep(i, a.size()) ans[i] = a[i] % (1 << j);
    return ans;
}

int main() {


    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];


    ll ans = 0;

    rep(j, 30) {

        vector<ll> al = md(a, j + 1);
        vector<ll> bl = md(b, j + 1);

        sort(al.begin(), al.end());
        sort(bl.begin(), bl.end());

        ll now = 0;
        rep(i, n) {
            now +=  check_bit(al[i], bl, j);
        }
        ll bit = now % 2;
        ll i_ans = bit << 1;
        ans += i_ans;
    }

    cout << ans << endl;

}
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

int main() {
    int n;
    cin >> n;

    vector<P> v(n);
    for (P &p : v) cin >> p.first >> p.second;

    map<ll, P> mp;
    set<P> ranges;
    auto end = [&]() -> set<P>::iterator {
        return ranges.end();
    };

    auto get_by_right = [&](ll l) -> set<P>::iterator {
        auto it = mp.lower_bound(l);
        if (it == mp.end()) return ranges.end();
        auto ans = ranges.find((*it).second);
        assert(ans != end());
        return ans;
    };

    auto in = [&](set<P>::iterator &it, ll l) -> bool {
        if (it == end()) return false;
        return (*it).first <= l && l <= (*it).second;
    };

    auto get_by_left = [&](ll l) -> set<P>::iterator {
        return ranges.lower_bound(P(l, 0));
    };

    auto clear = [&](P p) {
        assert(mp.find(p.second) != mp.end());
        assert(mp[p.second] == p);
        assert(ranges.find(p) != ranges.end());

        mp.erase(mp.find(p.second));
        ranges.erase(ranges.find(p));
    };

    auto insert = [&](ll left, ll right) {

        auto it = ranges.lower_bound(P(left, INF));
        if (it != ranges.end()) {
            assert(right < (*it).first);
        }
        if (it != ranges.begin()) {
            it--;
            assert((*it).second < left);
        }

        P p = {left, right};
        mp[right] = p;
        ranges.insert(p);
    };

    for (P p : v) {
        ll start = p.first;
        ll cnt = p.second;
        while (true) {
            set<P>::iterator it = get_by_right(p.first);
            if (in(it, start)) start = (*it).second + 1;
            else break;
        }

        ll now = start;
        while (true) {
            set<P>::iterator r = get_by_left(now);
            if (r == end()) {
                now = now + cnt - 1;
                break;
            } else if (in(r, now)) {
                now = (*r).second + 1;
            } else if ((*r).first <= now + cnt - 1) {
                ll m = (*r).first - now;
                cnt -= m;
                assert(cnt >= 0);
                now = (*r).first;
            } else {
                now = now + cnt - 1;
                break;
            }
        }

        vector<P> exclude;
        set<P>::iterator it = get_by_left(start);
        while (it != end() && (*it).first <= now) {
            exclude.push_back(*it);
            it++;
        }

        for (P ex: exclude) clear(ex);
        insert(start, now);

        cout << now << endl;

    }


}

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

struct Sushi {
    ll t, d;
    bool first;
};


std::istream &operator>>(std::istream &in, Sushi &o) {
    cin >> o.t >> o.d;
    return in;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Sushi> sushis(n);

    rep(i, n) cin >> sushis[i];
    sort(sushis.rbegin(), sushis.rend(), [](Sushi &s1, Sushi &s2) {
        return s1.d < s2.d;
    });

    {
        set<ll> t;
        rep(i, n) {
            if (t.find(sushis[i].t) == t.end()) {
                sushis[i].first = true;
                t.insert(sushis[i].t);
            } else {
                sushis[i].first = false;
            }
        }
    }

    vector<Sushi> v = [&] {
        vector<Sushi> res;
        rep(i, k) {
            res.push_back(sushis[i]);
        }
        sort(res.rbegin(), res.rend(), [&](Sushi &s1, Sushi &s2) {
            ll a = s1.d;
            ll b = s2.d;
            if (s1.first) a += INF;
            if (s2.first) b += INF;
            return a < b;

        });
        return res;
    }(); // おいしくないやつが最後
    vector<Sushi> u = [&] {
        vector<Sushi> res;
        rep(i, n) {
            if (i < k) continue;
            if (!sushis[i].first) continue;
            res.push_back(sushis[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }(); // おいしいやつが最後

    ll prev_dsum = [&] {
        ll sum = 0;
        for (Sushi &s : v) sum += s.d;
        return sum;
    }();
    ll t = [&] {
        set<ll> types;
        for (Sushi &s : v) types.insert(s.t);
        return types.size();
    }();
    ll ma = t * t + prev_dsum;
    while (!u.empty() && v.back().first == false) {
        Sushi pv = v.back();
        Sushi pu = u.back();
        v.pop_back();
        u.pop_back();

        prev_dsum -= pv.d;
        prev_dsum += pu.d;
        t++;

        ll now = t * t + prev_dsum;
        cmax(ma, now);
    }
    cout << ma << endl;

}
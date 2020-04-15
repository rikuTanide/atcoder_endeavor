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
const int mod = 1000000007;


P pass_kakutei_point(P kakutei_point, int yosen, int n, int k, set<ll> &tsukasha, vector<vector<ll>> &order) {
    P next(kakutei_point.first + 1, kakutei_point.second);
    if (next.first == n) next = P(0, kakutei_point.second + 1);
    if (yosen <= next.first) return next;
    ll member_id = order[next.first][next.second];
    if (tsukasha.find(member_id) == tsukasha.end()) return next;
    return pass_kakutei_point(next, yosen, n, k, tsukasha, order);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<ll>> order(n, vector<ll>(k));
    rep(i, n) rep(j, k) cin >> order[i][j];

    P kakutei_point(0, 0);
    set<ll> tsukasha;
    rep(i, k - 1) kakutei_point = pass_kakutei_point(kakutei_point, -1, n, k, tsukasha, order);

    auto in_waku = [&](int i, int j) {
        if (kakutei_point.second > j) return true;
        if (kakutei_point.second < j) return false;
        return kakutei_point.first >= i;
    };

    auto is_tsuka = [&](ll mid) {
        return tsukasha.find(mid) != tsukasha.end();
    };

    vector<set<ll>> tsuka_yosen(n);

    auto add = [&](ll mid, int yosen) {
        tsukasha.insert(mid);
        tsuka_yosen[yosen].insert(mid);
    };

    rep(i, n) {
        rep(j, k) {
            ll member_id = order[i][j];
            if (!in_waku(i, j)) continue;
            if (is_tsuka(member_id)) {
                kakutei_point = pass_kakutei_point(kakutei_point, i, n, k, tsukasha, order);
                if (kakutei_point.first >= i) continue;
                ll mid = order[kakutei_point.first][kakutei_point.second];
                add(mid, i);
            } else {
                add(member_id, i);
            }
        }
    }

    for (set<ll> &mids : tsuka_yosen) {
        for (ll mid : mids) {
            cout << mid << ' ';
        }
        cout << endl;
    }

}


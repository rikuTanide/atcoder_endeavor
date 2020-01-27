#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

const vector<char> hands = {'r', 's', 'p'};

ll dynamic_programing(vector<char> &sequence, map<char, ll> &points) {
    if (sequence.empty()) return 0;
    vector<map<char, ll>> dp(sequence.size());

    auto get = [&](ll i, char h) {
        if (i == -1) return 0ll;
        if (dp[i].find(h) == dp[i].end()) return 0ll;
        return dp[i][h];
    };

    auto set = [&](ll i, char h, ll point) {
        if (dp[i].find(h) == dp[i].end()) {
            dp[i][h] = point;
        } else {
            cmax(dp[i][h], point);
        }
    };

    auto get_point = [&](char a, char b) {
        if (a == 'r') {
            if (b == 'p') return points['p'];
            else return 0ll;
        }
        if (a == 's') {
            if (b == 'r') return points['r'];
            else return 0ll;
        }
        if (a == 'p') {
            if (b == 's') return points['s'];
            else return 0ll;
        }
    };

    for (ll i = 0; i < sequence.size(); i++) {
        for (char b : hands) {
            for (char h : hands) {
                if (b == h) continue;
                ll point = get_point(sequence[i], h);
                set(i, h, get(i - 1, b) + point);
            }
        }
    }
    return max(max(dp.back()['r'], dp.back()['s']), dp.back()['p']);
}

int main() {
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;

    string t;
    cin >> t;

    vector<vector<char>> t_m_k(k);
    for (ll i = 0; i < t.size(); i++) {
        t_m_k[i % k].push_back(t[i]);
    }

    map<char, ll> points = {
            {'r', r},
            {'s', s},
            {'p', p},
    };
    ll ans = 0;
    for (ll i = 0; i < k; i++) {
        ans += dynamic_programing(t_m_k[i], points);
    }
    cout << ans << endl;
}

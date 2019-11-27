#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;

int gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

vector<pair<ll, int >> factorize(ll n) {
    vector<pair<ll, int >> res;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) {
            continue;
        }
        res.emplace_back(i, 0);
        while (n % i == 0) {
            n /= i;
            res.back().second++;
        }
    }

    if (n != 1) res.emplace_back(n, 1);
    return res;

}


int main() {
    ll n;
    cin >> n;
    vector<pair<ll, int>> n_kaijo_soinsu_list;
    {
        map<ll, ll> n_kaijo_soinsu_map;
        for (ll i = 2; i <= n; i++) {
            vector<pair<ll, int>> i_soinsu_list = factorize(i);
            for (auto p : i_soinsu_list) {
                n_kaijo_soinsu_map[p.first] += p.second;
            }
        }
        for (auto sosu : n_kaijo_soinsu_map) {
            pair<ll, int> p(sosu.first, sosu.second);
            n_kaijo_soinsu_list.push_back(p);
        }
        cout << endl;

    }

    int ans = 0;

    for (int p = 0; p < n_kaijo_soinsu_list.size(); p++) {
        for (int q = p + 1; q < n_kaijo_soinsu_list.size(); q++) {
            for (int r = q + 1; r < n_kaijo_soinsu_list.size(); r++) {
                int pe = n_kaijo_soinsu_list[p].second;
                int qe = n_kaijo_soinsu_list[q].second;
                int re = n_kaijo_soinsu_list[r].second;

                if (pe >= 4 && qe >= 4 && re >= 2) {
                    ans++;
                }
                if (pe >= 4 && qe >= 2 && re >= 4) {
                    ans++;
                }
                if (pe >= 2 && qe >= 4 && re >= 4) {
                    ans++;
                }

            }
        }
    }

    for (int p = 0; p < n_kaijo_soinsu_list.size(); p++) {
        for (int q = p + 1; q < n_kaijo_soinsu_list.size(); q++) {
            int pe = n_kaijo_soinsu_list[p].second;
            int qe = n_kaijo_soinsu_list[q].second;

            if (pe >= 14 && qe >= 4) {
                ans++;
            }
            if (pe >= 4 && qe >= 14) {
                ans++;
            }
            if (pe >= 24 && qe >= 2) {
                ans++;
            }
            if (pe >= 2 && qe >= 24) {
                ans++;
            }

        }
    }

    for (int p = 0; p < n_kaijo_soinsu_list.size(); p++) {
        int pe = n_kaijo_soinsu_list[p].second;
        if (pe >= 74) {
            ans++;
        }

    }


    cout << ans << endl;

}


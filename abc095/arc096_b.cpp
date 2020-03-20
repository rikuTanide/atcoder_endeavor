#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;
const int ROW_MAX = 100;

struct Sushi {
    ll cost, nutrition;
};

int main() {
    int n;
    ll c;
    cin >> n >> c;

    vector<Sushi> sushi_lr(n), sushi_rl;
    rep(i, n) cin >> sushi_lr[i].cost >> sushi_lr[i].nutrition;
    sushi_rl = sushi_lr;
    reverse(sushi_rl.begin(), sushi_rl.end());
    rep(i, n) sushi_rl[i].cost = c - sushi_rl[i].cost;

    vector<ll> candidate;

    if (n == 1) {
        ll e1 = sushi_lr[0].nutrition - sushi_lr[0].cost;
        ll e2 = sushi_lr[0].nutrition - (c - sushi_lr[0].cost);
        ll ans = max({0ll, e1, e2});
        cout << ans << endl;
        ret();
    }

    auto check = [&] {
        vector<ll> lr_nutrition_sum(n);
        vector<ll> rl_nutrition_sum(n);

        rep(i, n) {
            lr_nutrition_sum[i] = sushi_lr[i].nutrition;
        }
        rep(i, n) {
            if (i == 0)continue;
            lr_nutrition_sum[i] += lr_nutrition_sum[i - 1];
        }

        rep(i, n) {
            rl_nutrition_sum[i] = sushi_rl[i].nutrition;
        }
        rep(i, n) {
            if (i == 0)continue;
            rl_nutrition_sum[i] += rl_nutrition_sum[i - 1];
        }


        vector<ll> rl_max_total(n);
        rep(i, n)rl_max_total[i] = rl_nutrition_sum[i] - sushi_rl[i].cost;

        vector<ll> lr_max_total(n);
        rep(i, n)lr_max_total[i] = lr_nutrition_sum[i] - sushi_lr[i].cost * 2;

        candidate.push_back(*max_element(rl_max_total.begin(), rl_max_total.end()));

        rep(i, n) {
            if (i == 0)continue;
            lr_max_total[i] = max(lr_max_total[i], lr_max_total[i - 1]);
        }

        rep(i, n - 1) {
            int rl = i;
            int lr = n - rl - 2;

            ll now = rl_max_total[rl] + lr_max_total[lr];
            candidate.push_back(now);
        }

    };
    check();
    swap(sushi_lr, sushi_rl);
    check();

    cout << *max_element(candidate.begin(), candidate.end()) << endl;

}



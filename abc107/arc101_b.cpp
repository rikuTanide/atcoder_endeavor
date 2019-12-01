#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

int comp(ll i, ll j) {
    if (i > j) {
        return -1;
    } else if (i == j) {
        return 1;
    } else {
        return 1;
    }
}

//vector<ll> as = {10};
//int n = 1;
int n;
vector<ll> as;

vector<ll> u_or_d;
vector<ll> ruisekiwa;

void makeUOrD(ll border) {
    rep(j, n) u_or_d[j] = comp(border, as[j]);
}

void makeRuisekiwa() {
    ruisekiwa[0] = 0;
    for (int i = 0; i <= n; i++) {
        ruisekiwa[i + 1] = ruisekiwa[i] + u_or_d[i];
    }
}

ll getRuisekiWa(ll index1, ll index2) {
    assert(index1 <= index2);
    return ruisekiwa[index2 + 1] - ruisekiwa[index1];
}

bool check() {
    ll count = 0;
    for (ll x = 0; x < n; x++) {
        for (ll y = x; y < n; y++) {
            ll rw = getRuisekiWa(x, y);
            if (rw >= 0) {
                count++;
            } else {
                count--;
            }
        }
    }
    return count >= 0;
}

int main() {
    cin >> n;
    as = vector<ll>(n);
    rep(i, n) cin >> as[i];

    u_or_d = vector<ll>(n);
    ruisekiwa = vector<ll>(n + 1);
    ll cell = 10e12;
    ll floor = -1;
    while (floor + 1 < cell) {
        ll mid = (cell + floor) / 2;
        makeUOrD(mid);
        makeRuisekiwa();
        if (!check()) {
            cell = mid;
        } else {
            floor = mid;
        }
    }
    cout << floor << endl;



}
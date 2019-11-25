#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

ll f(ll i) {
    if (i % 2 == 0) {
        return i / 2;
    } else {
        return 3 * i + 1;
    }

}

vector<P> kadan; // <takasa , futosa>


void prt(bool b) {
//    if (b) {
//        cout << "matome ";
//    } else {
//        cout << "       ";
//    }
//    for (int i = 0; i < kadan.size(); i++) {
//        cout << kadan[i].first << ' ';
//    }
//    cout << endl;
}

void matome() {

    for (int i = 0; i < kadan.size() - 1; i++) {
        if (kadan[i].first == kadan[i + 1].first) {
            kadan[i].second++;
            kadan.erase(kadan.begin() + i + 1);
            i--;
        }
    }
    prt(true);

}


int main() {
    int n;
    cin >> n;


    rep(i, n) {
        int h;
        cin >> h;
        P p(h, 1);
        kadan.push_back(p);
    }
    ll ans = 0;
    matome();
    while (kadan.size() > 1) {

        set<int, greater<int>> q;
        for (int i = 0; i < kadan.size(); i++) {
            q.insert(kadan[i].first);
        }
        int max = *q.begin();
        int max2 = *(++q.begin());
        int diff = max - max2;
        for (int i = 0; i < kadan.size(); i++) {
            if (kadan[i].first == max) {
                kadan[i].first = max2;
                ans += diff;
                prt(false);
            }
        }
        matome();
    }
    ans += kadan[0].first;

    cout << ans << endl;

}
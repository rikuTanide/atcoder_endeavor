#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

ll pw[20];


ll s(ll n) {
    ll ans = 0;
    while (n != 0) {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

vector<ll> ketaList(ll n) {
    vector<ll> a(20);
    for (ll j = 0; j < 16; j++) {
        a[j] = n % 10;
        n /= 10;
    }
    return a;
}

int main() {
    pw[0] = 1;
    for (ll i = 1; i < 20; i++) pw[i] = pw[i - 1] * 10;
    ll k;
    cin >> k;
    ll now = 1;
    for (ll i = 0; i < k; i++) {
        vector<ll>keta_list = ketaList(now);
        for (ll j = 0; j < 16; j++) {
            if (keta_list[j] == 9) continue;
            if (now * s(now + pw[j] * 9) < (now + pw[j] * 9) * s(now)) {
                break;
            } else {
                now += (9 - keta_list[j]) * pw[j];
            }
        }
        cout << now << endl;
        now++;
    }

}



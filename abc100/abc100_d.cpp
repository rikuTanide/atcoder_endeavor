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

ll mod2(ll n) {
    ll ans = 0;
    while (n % 2 == 0) {
        n /= 2;
        ans++;
    }
    return ans;
}

typedef tuple<ll, ll, ll> Cake;

int main() {

    ll n, m;
    cin >> n >> m;

    vector<Cake> cakes;

    rep(i, n) {
        ll x, y, z;
        cin >> x >> y >> z;

        Cake cake(x, y, z);
        cakes.push_back(cake);

    }

    ll ans = 0;
    for (int i = 0; i < (1 << 3); i++) {

        int x_s = 1;
        int y_s = 1;
        int z_s = 1;

        if (i & 1 == 1) {
            x_s = -1;
        }
        if (((i >> 1) & 1) == 1) {
            y_s = -1;
        }
        if (((i >> 2) & 1) == 1) {
            y_s = -1;
        }


        vector<ll> ary;
        for(Cake cake : cakes) {
            ll x = get<0>(cake);
            ll y = get<1>(cake);
            ll z = get<2>(cake);

            x *= x_s;
            y *= y_s;
            z *= z_s;

            ary.push_back(  x + y + z);
        }

        sort(ary.rbegin() , ary.rend());
        ll now = 0;
        for(int j = 0 ; j < m ; j ++) {
            now += ary[j];
        }
        ans = max(now, ans);
    }

    cout << ans << endl;

}



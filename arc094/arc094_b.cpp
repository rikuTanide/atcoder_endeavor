#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

//ll searchCenter(ll border, ll a, ll b) {
//    ll i = a + 1;
//
//    while (((i + 1) * (i + 1)) < border) {
//        i++;
//    }
//    return i;
//}

ll searchCenter(ll border, ll a, ll b) {
    ll floor = a + 1;
    ll ceil = b;
    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        if (mid * mid <=border) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }
    return floor;

}


ll searchPair(ll border, ll center, ll b) {
    ll i = center - 1;
    while ((center * (i + 1)) < border) {
        i++;
    }
    if (i == b) i--;
    return i;
}

int main() {

//    ifstream myfile("C:\\Users\\riku\\Downloads\\06.txt");
//    ofstream outfile("..\\log.txt");

    ll q;
//    myfile >> q;
    cin >> q;

    rep(i, q) {
        ll a, b;
        cin >> a >> b;
//        myfile >> a >> b;
        if (a > b) {
            swap(a, b);
        }

        ll border = a * b;

        ll center = searchCenter(border, a, b);
        ll pair = searchPair(border, center, b);

        ll left = pair - 1;
        ll right = center - 2;

        ll ans = right + left;
        if (center == b && pair == a) {

        } else {
            ans++;
        }

        if (center + 1 == pair - 1) {
            ans--;
        }

//        outfile << ans << endl;
        cout << ans << endl;

    }

//    outfile.flush();
//    outfile.close();
}
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
//const ll INF = 10e10;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
typedef tuple<int, int, int> Q;


int main() {
    int n, m;
    cin >> n >> m;

    vector<P> wars;
    rep(i, m) {
        int a, b;
        cin >> a >> b;

        P p(b, a);
        wars.push_back(p);
    }

    sort(wars.begin(), wars.end());


    int current_broken = wars[0].first - 1;
    int ans = 1;
    for(int i = 1 ; i < wars.size(); i ++) {
        P p = wars[i];
        if(p.second > current_broken ) {
            ans ++;
            current_broken = p.first - 1;
        }
    }

    cout << ans << endl ;

}


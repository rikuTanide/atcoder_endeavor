#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> times(25 * 100, 0);

    rep(i, n) {
        char m;
        int s, e;
        cin >> s >> m >> e;

        int sh = s / 100;
        int sm = s % 100;
        sm = sm / 5 * 5;

        int eh = e / 100;
        int em = e % 100;
        em = (em + 4) / 5 * 5;
        if (em == 60) {
            em = 0;
            eh++;
        }
        int sa = sh * 100 + sm;
        int ea = eh * 100 + em;

        times[sa]++;
        times[ea + 1]--;
    }

    for (int i = 0; i < times.size() - 1; i++) {
        times[i + 1] += times[i];
    }

    vector<P> ans;
    if (times[0] > 0) ans.push_back(P(0, -1));
    for (int i = 1; i < times.size() - 1; i++) {
        if (times[i] == 0 && times[i + 1] > 0) {
            ans.push_back(P(i + 1, 0));
        } else if (times[i] > 0 && times[i + 1] == 0) {
            ans.back().second = i;
        }
    }

    for (P p : ans) {
        printf("%04lld-%04lld\n", p.first, p.second);
    }

}

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

void recursive_comb(vector<int> &indexes, int s, int rest, std::function<void(vector<int> &)> &f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

void foreach_comb(int n, int k, std::function<void(vector<int> &)> f) {
    vector<int> indexes(k);
    recursive_comb(indexes, n - 1, k, f);
}

struct Barentain {
    int boy;
    int girl;
    int happiness;
};

int main() {

    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;

    vector<Barentain> barentains(r);
    rep(i, r) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;

        barentains[i].girl = x;
        barentains[i].boy = y;
        barentains[i].happiness = z;
    }

    int ans = 0;

    foreach_comb(n, p, [&](vector<int> &indexes) {
        vector<int> boy_values(m);
        for (Barentain &barentain: barentains) {
            if (find(indexes.begin(), indexes.end(), barentain.girl) != indexes.end()) {
                boy_values[barentain.boy] += barentain.happiness;
            }
        }
        sort(boy_values.rbegin(), boy_values.rend());

        int now = accumulate(boy_values.begin(), boy_values.begin() + q, 0);
        cmax(ans, now);
    });
    cout << ans << endl;
}


#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Testimony {
    int from, to;
    bool is_honest;
};

int main() {
    int n;
    cin >> n;

    vector<Testimony> testimonies;

    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            x--;
            Testimony testimony{(int)i, x, y == 1};
            testimonies.push_back(testimony);
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        bool b = [&]() {
            for (Testimony &testimony : testimonies) {
                int t_from = testimony.from;
                int t_to = testimony.to;
                bool test = testimony.is_honest;

                bool from_honesty = (i >> t_from) & 1;
                bool to_honesty = (i >> t_to) & 1;
                if (from_honesty) {
                    if (to_honesty == test) {
                        continue;
                    } else {
                        return false;
                    }
                } else {
                    continue;
                }
            }
            return true;
        }();

        if (b) {
            int now = __builtin_popcount(i);
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}
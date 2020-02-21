#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

int main() {

    int n, m;
    cin >> n >> m;

    string name, kit;
    cin >> name >> kit;
    vector<int> kit_count(26, 0);
    vector<int> name_count(26, 0);

    for (char c : name) name_count[c - 'A']++;
    for (char c : kit) kit_count[c - 'A']++;

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int nc = name_count[i];
        int kc = kit_count[i];
        if (nc > 0 && kc == 0) {
            cout << -1 << endl;
            ret();
        }
        if (kc == 0) continue;
        int now = (nc + kc - 1) / kc;
        cmax(ans, now);
    }

    cout << ans << endl;

}



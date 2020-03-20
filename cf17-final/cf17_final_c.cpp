#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

int check(int n, vector<int> &times) {
    int ans = 24;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = abs(times[i] - times[j]);
            assert(k <= 24);
            int now = min(k, 24 - k);
            cmin(ans, now);
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> times(n);
    rep(i, n) cin >> times[i];

    n++;
    times.push_back(0);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> tmp = times;
        tmp[i] = -tmp[i];
        int now = check(n, tmp);
        cmax(ans, now);
    }
    cout << ans << endl;
}


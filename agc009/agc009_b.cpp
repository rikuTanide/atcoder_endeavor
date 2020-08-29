#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<double, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int rec(int i, vector<vector<int>> &i_win) {
    if (i_win[i].empty()) return 0;
    vector<int> d;
    for (int to : i_win[i]) {
        int now = rec(to, i_win);
        d.push_back(now);
    }
    sort(d.begin(), d.end());
    rep(j, d.size()) {
        d[j] = d[j] + d.size() - j;
    }
    int ans = *max_element(d.begin(), d.end());
    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> i_win(n);

    rep(i, n - 1) {
        int a;
        cin >> a;
        a--;
        i_win[a].push_back(i + 1);
    }

    int ans = rec(0, i_win);
    cout << ans << endl;
}
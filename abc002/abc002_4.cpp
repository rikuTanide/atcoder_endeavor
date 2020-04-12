#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

bool is_all_friends(vector<vector<bool>> &is_friends, vector<int> &members) {
    for (int i : members) {
        for (int j : members) {
            if (is_friends[i][j]) {
                continue;
            }
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> is_friends(n, vector<bool>(n, false));
    rep(i, n) is_friends[i][i] = true;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        is_friends[x][y] = true;
        is_friends[y][x] = true;
    }

    int ans = 0;

    for (int i = 0; i < (1 << n); i++) {
        vector<int> members;
        for (int j = 0; j < n; j++) {
            if ((i >> j) & 1) {
                members.push_back(j);
            }
        }

        bool b = is_all_friends(is_friends, members);
        int size = members.size();
        if (b) cmax(ans, size);
    }
    cout << ans << endl;
}

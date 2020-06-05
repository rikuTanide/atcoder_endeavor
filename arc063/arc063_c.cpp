#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, ll> P;
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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> edges(n);
    rep(i, n - 1) {
        int x, y;
        cin >> x >> y;

        x--;
        y--;

        edges[x].push_back(y);
        edges[y].push_back(x);

    }

    vector<ll> d(n, -1);
    priority_queue<P> q;

    int k;
    cin >> k;
    rep(_, k) {
        int x, y;
        cin >> x >> y;
        x--;
        d[x] = y;
        q.emplace(-y, x);
    }

    while (!q.empty()) {
        int cur = q.top().second;
        q.pop();

        for (auto e : edges[cur]) {
            if (d[e] == -1) {
                d[e] = d[cur] + 1;
                q.push({-d[e], e});
            } else {
                if (abs(d[e] - d[cur]) != 1) {
                    cout << "No" << endl;
                    ret();
                }
            }
        }

    }

    cout << "Yes" << endl;
    for(int a : d) cout << a << endl;

}

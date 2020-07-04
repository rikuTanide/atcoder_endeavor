#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

bool check(string &s, string &t) {
    int c = 0;
    rep(i, s.size()) {
        if (s[i] != t[i]) c++;
    }
    return c == 1;
}

int main() {
    string first, last;
    int n;
    cin >> first >> last >> n;
    vector<string> tablet(n);
    rep(i, n) cin >> tablet[i];

    vector<vector<int>> edges(n + 2);

    if (first == last || check(first, last)) {
        cout << 0 << endl << first << endl << last << endl;
        ret();
    }


    rep(i, n) {
        string s = tablet[i];
        if (check(s, first)) {
            edges[i].push_back(n);
            edges[n].push_back(i);
        }
    }

    rep(i, n) {
        string s = tablet[i];
        if (check(s, last)) {
            edges[i].push_back(n + 1);
            edges[n + 1].push_back(i);
        }
    }

    rep(i, n) {
        rep(j, n) {
            if (i <= j) continue;
            string s = tablet[i];
            string t = tablet[j];

            if (!check(s, t)) continue;

            edges[i].push_back(j);
            edges[j].push_back(i);
        }
    }

    vector<int> parent(n + 2);
    vector<int> costs(n + 2, INT_MAX);

    struct Task {
        int next, prev, cost;
    };

    queue<Task> q;
    q.push({n, -1, 0});
    while (!q.empty()) {
        Task t = q.front();
        q.pop();

        for (int next : edges[t.next]) {
            if (costs[next] <= t.cost + 1) continue;
            costs[next] = t.cost + 1;
            parent[next] = t.next;
            q.push({next, t.next, t.cost + 1});
        }

    }

    if (costs[n + 1] == INT_MAX) {
        cout << -1 << endl;
        ret();
    }

    int now = n + 1;
    vector<int> ans;
    while (now != n) {
        ans.push_back(now);
        now = parent[now];
    }
    ans.push_back(now);

    reverse(ans.begin(), ans.end());

    cout << ans.size() - 2 << endl;

    for (int a : ans) {
        if (a == n) cout << first << endl;
        else if (a == n + 1) cout << last << endl;
        else cout << tablet[a] << endl;
    }

}

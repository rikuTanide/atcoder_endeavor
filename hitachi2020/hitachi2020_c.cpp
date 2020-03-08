#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
const ll INF = 1e15;
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

// 自分の三個となりにいるやつを求める
// 3こ隣にいるやつが多い奴から順番に3を割り振る
// 残ったやつを幅優先探索して1と2を割り振れるか確認


set<int> pairs_3(vector<vector<int>> &tos, int i) {
    struct Route {
        int now;
        int depth;
        int from;
    };

    queue<Route> q;
    q.push({i, 0, -1});

    set<int> ans;

    while (!q.empty()) {
        Route r = q.front();
        q.pop();

        if (r.depth == 3) {
            ans.insert(r.now);
            continue;
        }

        for (int to : tos[r.now]) {
            if (to == r.from) continue;
            q.push({to, r.depth + 1, r.now});
        }
    }
    return ans;
}

vector<set<int>> create_3_pairs(int n) {

    vector<vector<int>> tos(n);

    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tos[a].push_back(b);
        tos[b].push_back(a);
    }

    vector<set<int>> ans(n);

    for (int i = 0; i < n; i++) {
        set<int> now = pairs_3(tos, i);
        ans[i] = now;
    }
    return ans;
}


vector<int> determinate_3(int n, vector<set<int>> &pairs3) {
    set<P> rank;

    rep(i, n) {
        P p(-pairs3[i].size(), i);
        rank.insert(p);
    }

    vector<int> use3;
    for (int i = 0; i < n / 3; i++) {
        P p = *rank.begin();
        rank.erase(p);

        use3.push_back(p.second);
        set<int> &s = pairs3[p.second];

        for (int j : s) {

            rank.erase(P(-pairs3[j].size(), j));
            pairs3[j].erase(p.second);
            rank.insert(P(-pairs3[j].size(), j));
        }
        pairs3[p.second] = set<int>();
    }

    return use3;
}

vector<int> determinate_12(vector<set<int>> &tos, vector<int> &use_3, int n) {
    struct Route {
        int now;
        int depth;
        int from;
    };

    vector<int> ans(n, -1);
    for (int t : use_3) {
        ans[t] = 3;
    }

    rep(i, n) {
        if (ans[i] != -1) continue;
        if (tos[i].empty()) continue;
        queue<Route> q;
        q.push({i, 0, -1});
        while (!q.empty()) {
            Route r = q.front();
            q.pop();

            int a = r.depth % 2 + 1;
            if (ans[r.now] != -1 && ans[r.now] != a) {
                cout << -1 << endl;
                exit(0);
            }
            if (ans[r.now] == a) {
                continue;
            }

            ans[r.now] = a;

            for (int to : tos[r.now]) {
                if (to == r.from) continue;
                q.push({to, r.depth + 1, r.now});
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<set<int>> pairs_3 = create_3_pairs(n);
    vector<int> use3 = determinate_3(n, pairs_3);
    vector<int> ans = determinate_12(pairs_3, use3, n);

    queue<int> u3, u2, u1;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) u3.push(i);
        else if (i % 3 == 1)u1.push(i);
        else if (i % 3 == 2)u2.push(i);
    }

    rep(i, n) {
        int a = ans[i];
        if (a == 3) {
            if (u3.empty()) {
                cout << -1 << endl;
                ret();
            }
            ans[i] = u3.front();
            u3.pop();
        } else if (a == -1) {
            if (!u1.empty()) {
                a = 1;
            } else if (!u2.empty()) {
                a = 2;
            } else {
                cout << -1 << endl;
                ret();
            }
        }
        if (a == 1) {
            ans[i] = u1.front();
            u1.pop();
        } else if (a == 2) {
            ans[i] = u2.front();
            u2.pop();
        }
    }

    for (int a : ans) {
        cout << a << ' ';
    }

}

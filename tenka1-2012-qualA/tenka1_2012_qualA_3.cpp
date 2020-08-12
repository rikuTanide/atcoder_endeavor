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

string rec(string &s, int start, int end, vector<bool> &trace_friendly) {
    if (s[start] == '"') {
        // 引用
        if (s[end] == 'w') {
            // 敵対的引用
            trace_friendly.push_back(false);
            return rec(s, start + 1, end - 3, trace_friendly);
        } else {
            // 友好的引用
            trace_friendly.push_back(true);
            return rec(s, start + 1, end - 1, trace_friendly);
        }
    } else {
        // 最初の発言
        if (s[end] == 'w') {
            trace_friendly.push_back(false);
            reverse(trace_friendly.begin(), trace_friendly.end());
            return s.substr(start, end - 1 - start + 1);

        } else {
            trace_friendly.push_back(true);
            reverse(trace_friendly.begin(), trace_friendly.end());
            return s.substr(start, end - start + 1);

        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<set<int>> aggressive_list(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;

        a--;
        b--;
        aggressive_list[a].insert(b);
    }


    string s;
    cin >> s;
    vector<bool> trace_friendly;
    string start = rec(s, 0, s.size() - 1, trace_friendly);
    string id_str = start.substr(string("group").size());
    int start_id = atoi(id_str.c_str()) - 1;

    auto is_friendly = [&](int from, int to) -> bool {
        return aggressive_list[from].find(to) == aggressive_list[from].end();
    };

    vector<bool> prev(n);
    rep(i, n) {

        bool f = is_friendly(i, start_id);
        bool t = trace_friendly[0];

        prev[i] = f == t;
    }

    for (int i = 1; i < trace_friendly.size(); i++) {
        vector<bool> next(n, false);
        rep(from, n) {
            rep(to, n) {
                if (!prev[to]) continue;
                if (is_friendly(from, to) == trace_friendly[i]) next[from] = true;
            }
        }
        prev = next;
    }

    int ans = count(prev.begin(), prev.end(), true);
    cout << ans << endl;

}

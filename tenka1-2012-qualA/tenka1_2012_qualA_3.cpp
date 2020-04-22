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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

bool end_with(string &s, int start, int end, string needle) {
    end -= (needle.size() - 1);
    string t = s.substr(end, needle.size());
    return t == needle;
}

vector<P> rec(string &s, int start, int end) {
    assert(s[start] == '"' || s[start] == 'g');
    if (end_with(s, start, end, "\"ww")) {
        auto r = rec(s, start + 1, end - 3);
        r.emplace_back(start, end);
        return r;
    }
    if (end_with(s, start, end, "\"")) {
        auto r = rec(s, start + 1, end - 1);
        r.emplace_back(start, end);
        return r;
    }
    if (end_with(s, start, end, "w")) {
        return {P(start, end)};
    }
    return {P(start, end)};
}

template<typename ... Args>
std::string format(const std::string &fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
    return std::string(&buf[0], &buf[0] + len);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> aggressive(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        aggressive[a].insert(b);
    }

    string s;
    cin >> s;

    auto g = rec(s, 0, s.size() - 1);

//    for (P p : g) {
//        cout << p.first << ' ' << p.second << endl;
//    }

    vector<char> v(g.size());
    rep(i, g.size()) {
        P p = g[i];
//        cout << s[p.second] << endl;
        if (s[p.second] == 'w') v[i] = 'a';
        else v[i] = 'f';
    }

    int start = [&]() {
        P p = g.front();
        string u = s.substr(p.first, p.second - p.first + 1);
        rep(i, n) {
            string s = format("group%d", i + 1);
            if (s == u) return i;
            string t = format("group%dw", i + 1);
            if (t == u)return i;
        }
        __throw_runtime_error("konai");
    }();

    set<int> reachable;
    if (v.front() == 'f') {
        rep(i, n) if (aggressive[i].find(start) == aggressive[i].end()) reachable.insert(i);
    } else {
        rep(i, n) if (aggressive[i].find(start) != aggressive[i].end()) reachable.insert(i);
    }

    auto has_friendly = [&](int j) {
        if (reachable.size() > aggressive[j].size()) return true;
        for (int to : reachable) {
            if (aggressive[j].find(to) == aggressive[j].end()) return true;
        }
        return false;
    };

    auto has_aggressive = [&](int j) {
        for (int to : aggressive[j]) {
            if (reachable.find(to) != reachable.end()) {
                return true;
            }
        }
        return false;
    };

    rep(i, v.size()) {
        if (i == 0) continue;
        set<int> next;
        if (v[i] == 'f') {
            rep(j, n) {
                if (has_friendly(j)) {
                    next.insert(j);
                }
            }
        } else {
            rep(j, n) {
                if (has_aggressive(j)) {
                    next.insert(j);
                }
            }
        }
        reachable = next;
    }

    cout << reachable.size() << endl;

}


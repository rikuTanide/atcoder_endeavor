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

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

struct Movie {
    int type, start, end;

};

class Conv {
    ll cursor = 0;
    map<ll, ll> to_short; // <original, small >
    map<ll, ll> to_long; // <small, original>
    std::set<ll> tmp;


public:
    void set(ll original) {
        if (to_short.find(original) != to_short.end()) {
            return;
        }
        to_long[cursor] = original;
        to_short[original] = cursor;
        cursor++;
    }

    ll revert(ll after) {
        assert(to_long.find(after) != to_long.end());
        return to_long[after];
    }

    ll convert(ll original) {
        assert(to_short.find(original) != to_short.end());
        return to_short[original];
    }

    ll next() {
        return cursor;
    }

    // 前計算省略のため
    void cache(ll t) {
        tmp.insert(t);
    }

    void build() {
        for (ll t : tmp) {
            set(t);
        }
    }

};

int main() {
    int n;
    cin >> n;
    vector<int> happiness(n);
    rep(i, n) cin >> happiness[i];
    map<int, vector<Movie>> movies_map;
    Conv cv;
    {
        vector<Movie> ms(n);
        rep(i, n) cin >> ms[i].type >> ms[i].start >> ms[i].end;
        sort(ms.begin(), ms.end(), [](Movie &m1, Movie &m2) { return m1.start < m2.start; });

        for (Movie &m : ms) {
            cv.cache(m.start);
            cv.cache(m.end);
        }
        cv.build();
        for (Movie &m : ms) m.start = cv.convert(m.start);
        for (Movie &m : ms) m.end = cv.convert(m.end);
        for (Movie &movie: ms) movies_map[movie.type].push_back(movie);
    }

    vector<ll> dp(cv.next(), 0);
    rep(i, cv.next()) {
        for (auto &e : movies_map) {
            int now = i;
            int combo = 0;
            int h = 0;
            for (Movie &m : e.second) {
                if (now < m.start) {
                    now = m.end;
                    h += happiness[combo];
                    combo++;
                    cmax(dp[now], dp[i] + h);
                }
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}

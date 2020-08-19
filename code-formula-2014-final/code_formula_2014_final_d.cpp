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


struct Movie {
    int type, start, end;
};

std::istream &operator>>(std::istream &in, Movie &o) {
    in >> o.type >> o.start >> o.end;
    o.type--;
    return in;
}

int main() {
    int n;
    cin >> n;
    vector<ll> happiness(n);
    rep(i, n)cin >> happiness[i];

    vector<Movie> movies(n);
    rep(i, n) cin >> movies[i];

    Conv conv;
    for (Movie movie : movies) conv.cache(movie.start);
    for (Movie movie : movies) conv.cache(movie.end - 1);
    conv.build();
    for (Movie &movie: movies) movie.start = conv.convert(movie.start);
    for (Movie &movie: movies) movie.end = conv.convert(movie.end - 1);

    vector<vector<Movie>> types(n);
    for (Movie movie : movies) types[movie.type].push_back(movie);
    rep(i, n)sort(types[i].begin(), types[i].end(), [](Movie m1, Movie m2) {
            return m1.end < m2.end;
        });


    sort(movies.begin(), movies.end(), [](Movie m1, Movie m2) {
        return m1.start < m2.start;
    });


    vector<ll> dp(conv.next());
    rep(i, n) {
        Movie movie = movies[i];
        vector<Movie> tmp = {movie};
        for (Movie seq : types[movie.type]) {
            if (movie.type != seq.type) continue;
            if (!(movie.end < seq.start)) continue;
            tmp.push_back(seq);
        }
        ll ma = *max_element(dp.begin(), dp.begin() + movie.start);
        ll next_value = ma;
        rep(j, tmp.size()) {
            Movie seq = tmp[j];
            next_value += happiness[j];
            cmax(dp[seq.end], next_value);
        }
    }

    ll ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;

}

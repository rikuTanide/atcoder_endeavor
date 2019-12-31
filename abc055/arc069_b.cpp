#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct mint {
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}

    mint &operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator-=(const mint a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }

    mint &operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }

    mint pow(ll t) const {
        if (!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const {
        return pow(mod - 2);
    }

    mint &operator/=(const mint a) {
        return (*this) *= a.inv();
    }

    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

class CirclePermutation {

    vector<char> v;

    int convert(int i) {
        int ni = i;
        if (i < 0) {
            ni += v.size();
        }
        if (i >= v.size()) {
            ni %= v.size();
        }
        return ni;
    }

public:
    CirclePermutation(int n, char d) {
        v.resize(n, d);
    }


    void set(int i, char c) {
        int ni = convert(i);
        v[ni] = c;
    }

    char get(int i) {
        int ni = convert(i);
        return v[ni];
    }

    void print() {
        for (char c : v) {
            cout << c;
        }
        cout << endl;
    }

};

char turn(char c) {
    return c == 'S' ? 'W' : 'S';
}

bool check(CirclePermutation &advocates, CirclePermutation &zoo, int n) {
    for (int i = 0; i < n; i++) {
        char a = advocates.get(i);
        char center = zoo.get(i);
        char left = zoo.get(i - 1);
        char right = zoo.get(i + 1);

        char right_expect = ' ';
        if (center == 'S') {
            if (a == 'o') {
                right_expect = left;
            } else {
                right_expect = turn(left);
            }
        } else {
            if (a == 'o') {
                right_expect = turn(left);
            } else {
                right_expect = left;
            }
        }
        if (right == right_expect || right == ' ') {
            zoo.set(i + 1, right_expect);
        } else {
            return false;
        }
    }
    return true;
}

bool construction(CirclePermutation &advocates, int n, char last, char first, char second) {
    CirclePermutation zoo(n, ' ');
    zoo.set(n - 1, last);
    zoo.set(n, first);
    zoo.set(n + 1, second);
    if (check(advocates, zoo, n)) {
        zoo.print();
        return true;
    }
    return false;
}


int main() {

    int n;
    cin >> n;

    CirclePermutation advocates(n, ' ');

    rep(i, n) {
        char a;
        cin >> a;
        advocates.set(i, a);
    }

    // 先頭が羊
    {
        if (advocates.get(0) == 'o') {
            if (construction(advocates, n, 'W', 'S', 'W')) {
                return 0;
            }
            if(construction(advocates, n, 'S', 'S', 'S')) {
                return 0;
            }
        } else {
            if(construction(advocates, n, 'W', 'S', 'S')){
                return 0;
            }
            if(construction(advocates, n, 'S', 'S', 'W')){
                return 0;
            }
        }
    }

    // 先頭が狼
    {
        if (advocates.get(0) == 'x') {
            if(construction(advocates, n, 'W', 'W', 'W')){
                return 0;
            }
            if(construction(advocates, n, 'S', 'W', 'S')){
                return 0;
            }
        } else {
            if(construction(advocates, n, 'W', 'W', 'S')){
                return 0;
            }
            if(construction(advocates, n, 'S', 'W', 'W')){
                return 0;
            }
        }
    }

    cout << -1 << endl;

}

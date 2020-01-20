#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
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

class CumulativeSum {
    vector<mint> numbers;
    vector<mint> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, mint value) {
        numbers[i] = value;
    }

    mint getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return 0;
        return sums[i];
    }

    mint getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

class Inchworm {
    int start;
    int end;

    int right;
    int left;

public:
    Inchworm(int start, int end) : start(start), end(end), right(start), left(start) {};


    bool next() {
        if (right == end) {
            return false;
        }
        right++;
        assert(left < right);
        return true;
    }

    int getRight() {
        return right;

    }

    int getLeft() {
        return left;
    }

    void moveLeft() {
        left++;
        assert(left <= right);
    }

};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> supplements(n);
    rep(i, n) cin >> supplements[i];

    Inchworm inchworm(0, n - 1);

    set<int> used;

    vector<P> segments;
    do {
        int right = inchworm.getRight();
        int next = supplements[right];

        while (contain(used, next)) {
            int left = inchworm.getLeft();
            int left_supplement = supplements[left];
            used.erase(left_supplement);
            inchworm.moveLeft();
        }
        int left = inchworm.getLeft();
        segments.emplace_back(left, right);
        used.insert(next);
    } while (inchworm.next());

    vector<mint> dp(n + 1, 0);
    vector<mint> sum(n + 1, 0);
    dp[0] = 1;
    sum[0] = 1;

    for (P p : segments) {
        mint up = sum[p.second];
        if (p.first != 0) {
            up -= sum[p.first - 1];
        }
        sum[p.second + 1] = sum[p.second] + up;
        dp[p.second + 1] = up;
    }

    cout << dp.back().x << endl;

}
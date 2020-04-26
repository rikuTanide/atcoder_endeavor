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

    friend std::istream &operator>>(std::istream &in, mint &o) {
        ll a;
        in >> a;
        o = a;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const mint &o) {
        out << o.x;
        return out;
    }

};

void tow_pointer(int n,
                 function<bool(int left)> check_begin,
                 function<void(int left)> begin,
                 function<bool(int right)> check_right,
                 function<void(int right)> push_right,
                 function<void(int left)> pop_left,
                 function<void(int left, int right)> dead_end
) {

    auto go = [&](P range) {
        int right = -1;
        for (int left = range.first; left <= range.second; left++) {
            if (right < left) {
                right = left;
                begin(left);
            }
            while (right + 1 <= range.second && check_right(right + 1)) {
                right++;
                push_right(right);
            }
            dead_end(left, right);
            pop_left(left);
        }
    };


    auto get_ranges = [&] {
        vector<bool> enable_items(n);
        rep(i, n) enable_items[i] = check_begin(i);

        auto start = [&](int i) {
            if (i == 0) {
                return enable_items[i] == true;
            }
            if (!enable_items[i - 1] && enable_items[i]) {
                return true;
            }
            return false;
        };

        auto end = [&](int i) {

            if (i == n - 1) {
                return enable_items[i] == true;
            }

            if (enable_items[i] && !enable_items[i + 1]) {
                return true;
            }

            return false;
        };

        vector<P> ans;
        P p;
        rep(i, n) {
            if (start(i)) {
                p = P(i, -1);
            }
            if (end(i)) {
                p.second = i;
                ans.push_back(p);
            }
        }
        return ans;
    };


    vector<P> ranges = get_ranges();
    for (P range: ranges) go(range);
}

vector<P> get_range(vector<ll> &takoyaki_tree, int n) {
    vector<P> ans;
    // この要素は単体で条件を満たすか？
    auto check_begin = [&](int left) {
        return takoyaki_tree[left] == -1;
    };

    // leftを左として尺を初期化しろ
    auto begin = [&](int left) {
//        sum = takoyaki_tree[left];
        ans.push_back(P(left, left));
    };

    // 右に1個伸びれるか確認しろ
    // 次の「1個右の要素は」rightだ
    auto check_right = [&](int right) {
//        return sum * takoyaki_tree[right] <= k;
        return true;
    };

    // 右に1このびろ
    // 次の「1個右の要素は」rightだ
    auto push_right = [&](int right) {
//        sum *= takoyaki_tree[right];
        ans.back().second = right;
    };

    // 左を1個捨てろ
    // 捨てる左の要素はleftだ
    auto pop_left = [&](int left) {
//        assert(sum % takoyaki_tree[left] == 0);
//        sum /= takoyaki_tree[left];
    };


    // 尺が伸びれるところまで伸びた
    auto dead_end = [&](int left, int right) {
//        printf("%d %d\n", left, right);
    };


    tow_pointer(
            n,
            check_begin,
            begin,
            check_right,
            push_right,
            pop_left,
            dead_end
    );
    for (P &p : ans) p.first--;
    for (P &p : ans) p.second++;
    return ans;
}

mint combination(ll n, ll a) {
    mint bunbo = 1;
    for (int i = 1; i <= a; i++) {
        bunbo *= i;
    }
    mint bunshi = 1;
    for (int i = 1; i <= a; i++) {
        bunshi *= (n - a + i);
    }

    return bunshi / bunbo;

}

int main() {
    int n;
    cin >> n;

    vector<ll> takoyaki_tree(n);
    rep(i, n) cin >> takoyaki_tree[i];

    auto ps = get_range(takoyaki_tree, n);

    mint ans = 1;

    for (P p : ps) {
        ll distance = p.second - p.first - 1;
        ll up = takoyaki_tree[p.second] - takoyaki_tree[p.first] + 1;

        mint now = combination(distance + up - 1, distance);
        ans *= now;
    }
    cout << ans << endl;
}


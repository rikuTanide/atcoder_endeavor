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

template<class T, class F>
struct SegmentTree {
    F f;
    T ti;
    vector<T> dat;
    int sz;

    SegmentTree(const F &f, const T &ti) : f(f), ti(ti) {}

    void build(const vector<T> &v) {
        assert(v.size());
        sz = 1;
        while (sz < v.size())sz <<= 1;
        dat.resize(sz << 1, ti);
        for (int i = 0; i < v.size(); i++)dat[sz - 1 + i] = v[i];
        for (int i = sz - 2; i >= 0; i--)dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);
    }

    inline void update(int k, T x) {
        k += sz - 1;
        dat[k] = x;
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline void add(int k, int x) {
        k += sz - 1;
        dat[k] = f(dat[k], x);
        while (k) {
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    inline T query(int a, int b) {
        if (a == -1) {
            return query(0, b) + 1;
        }
        return query(a, b, 0, 0, sz);
    }

    T query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)return ti;
        if (a <= l && r <= b)return dat[k];
        return f(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

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

vector<int> create_back(int n, vector<int> v) {
    reverse(v.begin(), v.end());
    v.push_back(v.back());

    n++;

    set<int> used;
    // この要素は単体で条件を満たすか？
    auto check_begin = [&](int left) {
        return !contain(used, v[left]);
    };

    // leftを左として尺を初期化しろ
    auto begin = [&](int left) {
        used.clear();
        used.insert(v[left]);
    };

    // 右に1個伸びれるか確認しろ
    // 次の「1個右の要素は」rightだ
    auto check_right = [&](int right) {
        return !contain(used, v[right]);
    };

    // 右に1このびろ
    // 次の「1個右の要素は」rightだ
    auto push_right = [&](int right) {
        used.insert(v[right]);
    };

    // 左を1個捨てろ
    // 捨てる左の要素はleftだ
    auto pop_left = [&](int left) {
        used.erase(v[left]);
    };
    vector<int> back(n, INT_MAX);


    // 尺が伸びれるところまで伸びた
    auto dead_end = [&](int left, int right) {
        back[left] = right + 1;
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

    return back;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    rep(i, n) cin >> v[i];
    vector<int> back = create_back(n, v);

    auto f = [](mint i, mint j) { return i + j; };
    SegmentTree<mint, decltype(f)> segmentTree(f, 0);
    segmentTree.build(vector<mint>(n));

    auto get = [&](int l, int r) -> mint {
        if (r == n) {
            return segmentTree.query(l, r) + 1;
        }
        return segmentTree.query(l, r + 1);
    };

    for (int i = n - 1; i >= 0; i--) {
        int r = back[i];
        mint now = get(i, r);
        segmentTree.update(i, now);
    }

    mint ans = segmentTree.query(0, 1);

    cout << ans << endl;

}

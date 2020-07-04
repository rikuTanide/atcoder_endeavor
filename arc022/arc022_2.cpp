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

int main() {
    int n;
    cin >> n;

    vector<int> candies(n);
    rep(i, n) cin >> candies[i];


    // この要素は単体で条件を満たすか？
    auto check_begin = [&](int left) {
        return true;
    };

    set<int> used;

    // leftを左として尺を初期化しろ
    auto begin = [&](int left) {
        int candy = candies[left];
        used.insert(candy);
    };

    // 右に1個伸びれるか確認しろ
    // 次の「1個右の要素は」rightだ
    auto check_right = [&](int right) {
        int candy = candies[right];
        return !contain(used, candy);
    };

    // 右に1このびろ
    // 次の「1個右の要素は」rightだ
    auto push_right = [&](int right) {
        int candy = candies[right];
        used.insert(candy);
    };

    // 左を1個捨てろ
    // 捨てる左の要素はleftだ
    auto pop_left = [&](int left) {
        int candy = candies[left];
        used.erase(candy);
    };

    ll ans = 0;

    // 尺が伸びれるところまで伸びた
    auto dead_end = [&](int left, int right) {
        ll now = right - left + 1;
        cmax(ans, now);
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
    cout << ans << endl;

}
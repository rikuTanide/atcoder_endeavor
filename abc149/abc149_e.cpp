#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;


ll count_pair(ll x, ll a, vector<ll> &audiences) {
    ll need_b = x - a;
    auto it = lower_bound(audiences.begin(), audiences.end(), need_b);
    ll count = audiences.end() - it;
    return count;
}

ll get_max_x(vector<ll> &audiences, ll m) {
    ll floor = 2;
    ll ceil = INF;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll ans = 0;
        for (ll a : audiences) {
            ans += count_pair(mid, a, audiences);
        }
        if (m <= ans) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }
    return floor;
}

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return 0;
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

ll sum_pair(ll count, ll a, CumulativeSum &cs) {

    ll a_sum = a * count;
    ll b_sum = cs.getSum(count - 1);

    ll sum = a_sum + b_sum;

    return sum;
}


int main() {

    ll n, m;
    cin >> n >> m;

    vector<ll> audiences(n);
    rep(i, n) cin >> audiences[i];
    sort(audiences.begin(), audiences.end());

    ll max_x = get_max_x(audiences, m);

    CumulativeSum cs(n);
    vector<ll> rev = audiences;
    reverse(rev.begin(), rev.end());
    rep(i, n) cs.set(i, rev[i]);
    cs.calculate();


    ll sum = 0;
    ll total_count = 0;
    for (auto a : audiences) {
        ll count = count_pair(max_x, a, audiences);
        total_count += count;
        sum += sum_pair(count, a, cs);
    }

    ll diff = (total_count - m) * max_x;
    ll ans = sum - diff;

    cout << ans << endl;
}

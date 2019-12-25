#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
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

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(ll n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(ll i, ll value) {
        numbers[i] = value;
    }

    ll getSum(ll i) {
        if (i == -1) return 0;
        if (i == sums.size()) return 0;
        return sums[i];
    }

    ll getSectionSum(ll start, ll end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (ll i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

    ll lb(ll k) {
        auto it = lower_bound(sums.begin(), sums.end(), k);
        return distance(sums.begin(), it);
    }

};


int main() {

    ll n, k;
    cin >> n >> k;

    map<ll, ll> numbers;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        numbers[a] += b;
    }

    map<ll, ll> index_to_ans;

    CumulativeSum cs(numbers.size());
    {
        ll i = 0;
        for (auto e : numbers) {
            cs.set(i, e.second);
            index_to_ans[i] = e.first;
            i++;
        }
    }
    cs.calculate();
    ll index = cs.lb(k);

    cout << index_to_ans[index] << endl;

}


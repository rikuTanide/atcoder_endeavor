#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

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
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void build() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> book_prices(n);
    vector<int> book_genres(n);

    rep(i, n) cin >> book_prices[i] >> book_genres[i], book_genres[i]--;

    vector<vector<int>> books(10);
    rep(i, n) books[book_genres[i]].push_back(book_prices[i]);

    rep(i, 10) sort(books[i].rbegin(), books[i].rend());

    vector<ll> prev(k + 1, -1);
    prev[0] = 0;

    rep(i, 10) {

        int size = books[i].size();
        CumulativeSum cs(size + 1);
        rep(j, size) {
            ll price = books[i][j];
            cs.set(j + 1, price);
        }
        cs.build();

        vector<ll> next(k + 1, -1);

        auto set = [&](int i, ll value) {
            if (i > k) return;
            cmax(next[i], value);
        };

        rep(j, size + 1) {
            ll price_sum = cs.getSum(j) + max(0, j - 1) * j;
            rep(l, k + 1) {
                if (prev[l] == -1)continue;
                set(l + j, prev[l] + price_sum);
            }
        }
        prev = next;
    }

    cout << prev[k] << endl;

}
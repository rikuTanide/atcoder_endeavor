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


ll calc_sum(int n, ll x, ll k, vector<ll> &numbers) {
    ll s = 0, t = 0;
    for (ll a : numbers) {
        if (a > 0) {
            int floor = -1, ceil = n;
            while (floor + 1 < ceil) {
                int mid = (floor + ceil) / 2;
                ll m = numbers[mid];
                if (a * m <= x) floor = mid;
                else ceil = mid;
            }
            s += ceil;
        } else if (a < 0) {
            int floor = -1, ceil = n;
            while (floor + 1 < ceil) {
                int mid = (floor + ceil) / 2;
                ll m = numbers[mid];
                if (a * m <= x) ceil = mid;
                else floor = mid;
            }
            s += n - ceil;
        } else if (x >= 0) {
            s += n;
        }
        if (a * a <= x) t++;
    }
    return (s - t) / 2;
}

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    ll floor = -INF, ceil = INF;

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll sum = calc_sum(n, mid, k, numbers);
        if (sum >= k) ceil = mid;
        else floor = mid;
    }

    cout << ceil << endl;

}

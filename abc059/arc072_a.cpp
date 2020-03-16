#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, int> P;
const ll INF = 1e15;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

bool is_over(ll target, ll now) {
    assert(target == -1 || target == 1);
    if (target == 1) {
        return now >= 1;
    } else {
        return now <= -1;
    }
}

ll calc_to(ll target, ll now_sum, ll now) {
    if (is_over(target, now_sum + now)) {
        return now;
    } else {
        ll to = target - now_sum;
        assert(now_sum + to == target);
        return to;
    }
}


int main() {
    int n;
    cin >> n;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    ll ans = INF;
    {
        ll sum = 0;
        // +-+-
        vector<ll> tos(n, 0);
        rep(i, n) {
            ll target = i % 2 == 0 ? 1 : -1;
            ll to = calc_to(target, sum, numbers[i]);
            tos[i] = to;
            sum += to;
        }

        ll diff = 0;
        rep(i, n) diff += abs(numbers[i] - tos[i]);
        cmin(ans, diff);
    }
    {
        ll sum = 0;
        // +-+-
        vector<ll> tos(n, 0);
        rep(i, n) {
            ll target = i % 2 == 1 ? 1 : -1;
            ll to = calc_to(target, sum, numbers[i]);
            tos[i] = to;
            sum += to;
        }

        ll diff = 0;
        rep(i, n) diff += abs(numbers[i] - tos[i]);
        cmin(ans, diff);
    }
    cout << ans << endl;
}

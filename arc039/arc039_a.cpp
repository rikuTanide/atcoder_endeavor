#include <bits/stdc++.h>
#include <cmath>

//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;

bool contain(set<string> &s, string a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

class Keta {

    // 0桁目が一番左のくらい
    vector<int> digits;

public:
    Keta(ll i) : digits(i == 0 ? 1 : log10(i) + 1) {
        for (int k = 0; k < digits.size(); k++) {
            digits[k] = i % 10;
            i /= 10;
        }
        reverse(digits.begin(), digits.end());
    }

    int keta() {
        return digits.size();
    }

    int get(int index) {
        assert(index < keta());
        return digits[index];
    }

    void set(int index, int value) {
        digits[index] = value;
    }

    ll to_int() {
        ll ans = 0;
        for (int i = 0; i < keta(); i++) {
            ans += digits[i];
            ans *= 10;
        }
        ans /= 10;
        return ans;
    }
};

int main() {
    int a, b;
    cin >> a >> b;

    int ans1 = [&]() {
        int max_a = 0;
        for (int i = 0; i < 3; i++) {
            Keta keta(a);
            keta.set(i, 9);
            int ad = keta.to_int();
            cmax(max_a, ad);
        }
        return max_a - b;
    }();

    int ans2 = [&]() {
        int min_b = INT_MAX;
        for (int i = 0; i < 3; i++) {
            Keta keta(b);
            keta.set(i, i == 0 ? 1 : 0);
            int bd = keta.to_int();
            cmin(min_b, bd);
        }
        return a - min_b;
    }();


    cout << max(ans1, ans2) << endl;
}

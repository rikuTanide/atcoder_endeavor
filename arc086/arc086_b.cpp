#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
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


int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n)cin >> numbers[i];

    auto ma_it = max_element(numbers.begin(), numbers.end());
    ll ma = *ma_it;
    int ma_i = distance(numbers.begin(), ma_it);
    auto mi_it = min_element(numbers.begin(), numbers.end());
    ll mi = *mi_it;
    int mi_i = distance(numbers.begin(), mi_it);

    vector<P> ans;

    if (ma + mi >= 0) {
        rep(i, n) {
            if (numbers[i] < 0) ans.push_back(P(ma_i, i));
        }
        for (int i = 1; i < n; i++) {
            ans.push_back(P(i - 1, i));
        }
    } else {
        rep(i, n) {
            if (numbers[i] > 0) ans.push_back(P(mi_i, i));
        }
        for (int i = n - 2; i >= 0; i--) {
            ans.push_back(P(i + 1, i));
        }
    }


    cout << ans.size() << endl;
    for (P p : ans) {
        printf("%lld %lld\n", p.first + 1, p.second + 1);
    }

}


#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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


P culc_point(vector<int> numbers, int takahashi, int aoki) {
    if (takahashi > aoki) swap(takahashi, aoki);
    vector<int> next;
    rep(i, numbers.size()) {
        if (takahashi <= i && i <= aoki) {
            next.push_back(numbers[i]);
        }
    }

    P ans(0, 0);
    rep(i, next.size()) {
        if (i % 2 == 0) ans.first += next[i];
        else ans.second += next[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];

    int ans = INT_MIN;
    for (int takahashi = 0; takahashi < n; takahashi++) {
        int aoki_pa = INT_MIN;
        int takahashi_pa = INT_MIN;
        for (int aoki = 0; aoki < n; aoki++) {
            if (takahashi == aoki) continue;
            P p = culc_point(numbers, takahashi, aoki);
            int takahashi_p = p.first;
            int aoki_p = p.second;
            if (aoki_p > aoki_pa) {
                aoki_pa = aoki_p;
                takahashi_pa = takahashi_p;
            }
        }
        cmax(ans, takahashi_pa);
    }
    cout << ans << endl;
}

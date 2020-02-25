#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


int main() {

    int n;
    cin >> n;
    vector<ll> as(n), bs(n);
    rep(i, n) cin >> as[i];
    rep(i, n) cin >> bs[i];

    ll a_all = accumulate(as.begin(), as.end(), 0ll),
            b_all = accumulate(bs.begin(), bs.end(), 0ll);
    if (a_all > b_all) {
        cout << "No" << endl;
        ret();
    }

    ll turn = b_all - a_all;

    ll a_count = 0;

    for (int i = 0; i < n; i++) {
        if (as[i] == bs[i]) continue;
        if (as[i] < bs[i]) {
            a_count += (bs[i] - as[i] + 1) / 2;
        }
    }

    if (a_count <= turn) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}

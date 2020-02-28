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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    vector<ll> abss = numbers;
    rep(i, n) abss[i] = abs(numbers[i]);
    sort(abss.rbegin(), abss.rend());

    int m_count = 0;
    for (ll l : numbers) if (l < 0) m_count++;
    if (m_count % 2 == 0) {
        cout << accumulate(abss.begin(), abss.end(), 0ll) << endl;
        ret();
    }

    ll ans = accumulate(abss.begin(), abss.end() - 1, 0ll);
    ans -= abss.back();
    cout << ans << endl;

}
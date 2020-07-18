#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;



int main() {
    int n, v, p;
    ll m;
    cin >> n >> m >> v >> p;

    vector<ll> problems(n);
    rep(i, n) cin >> problems[i];

    sort(problems.rbegin(), problems.rend());

    auto ct = [&](ll x) -> int {
        return count_if(problems.begin(), problems.end(), [&](ll k) { return k >= x; });
    };

    auto check = [&](ll x) -> bool {

        ll border = problems[p - 1];

        if (x >= border) return true;
        if (x + m < border) return false;

        int vi = v;
        rep(i, n) {
            if (i < p - 1) vi--;
            else if (problems[i] <= x) vi--;
        }

        if (vi <= 0) return true;

        ll avc = vi * m;

        rep(i, n) {
            if (i < p - 1) continue;
            if (problems[i] <= x) continue;
            avc -= ((x + m) - problems[i]);
        }

        return avc <= 0;

    };

    ll floor = 0, ceil = INF;

    check(5);

    if (check(floor)) {
        cout << n << endl;
        ret();
    }

    while (floor + 1 < ceil) {
        ll mid = (floor + ceil) / 2;
        ll ok = check(mid);
        if (ok) ceil = mid;
        else floor = mid;
    }


    cout << ct(ceil) << endl;

}
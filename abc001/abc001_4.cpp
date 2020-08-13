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

int main() {
    int n;
    cin >> n;

    vector<int> imos(3000, 0);

    rep(_, n) {
        int start, end;
        scanf("%d-%d", &start, &end);
        start = start / 5 * 5;
        end = (end + 4) / 5 * 5;

        if (start - (start % 100) == 60) start += 40;
        if (end - (end % 100) == 60) end += 40;

        imos[start]++;
        imos[end + 1]--;
    }

    rep(i, 2800) imos[i + 1] += imos[i];


    vector<P> ans;

    rep(i, 2800) {
        int prev = (i == 0) ? 0 : imos[i - 1];
        int now = imos[i];
        if (prev == 0 && now > 0) ans.push_back({i, -1});
        if (prev > 0 && now == 0) ans.back().second = i - 1;
    }

    for (P p : ans) printf("%04lld-%04lld\n", p.first, p.second);

}

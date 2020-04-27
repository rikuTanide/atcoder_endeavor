#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

P get_count(ll lr, ll x) {
    assert(x >= 0);
    assert(lr >= x);

    ll nokori = lr - x;
    assert(nokori % 2 == 0);
    ll add = nokori / 2;

    ll r = x + add;
    ll l = add;

    return P(r, l);

}


int main() {
    int n;
    ll d, x, y;
    cin >> n >> d >> x >> y;

    x = abs(x);
    y = abs(y);

    if (x % d != 0 || y % d != 0) {
        cout << 0 << endl;
        ret();
    }

    x /= d;
    y /= d;


    vector<vector<double>> pascal(1001);
    pascal[0].push_back(1);
    {
        auto get = [&](int i, int j) {
            if (i == -1 || j == -1) return 0.0;
            if (pascal[i].size() <= j) return 0.0;
            return pascal[i][j];
        };
        rep(i, 1001) {
            if (i == 0) continue;
            rep(j, i + 1) {
                double a = get(i - 1, j - 1);
                double b = get(i - 1, j);

                double c = (a + b) / 2;
                pascal[i].push_back(c);
            }
        }
    }

    double ans = 0;
    rep(i, n + 1) {
        int lr = i;
        int ud = n - i;

        if (lr < x) continue;
        if (ud < y) continue;
        if ((lr - x) % 2 != 0) continue;
        if ((ud - y) % 2 != 0) continue;

        P lrc = get_count(lr, x);
        P udc = get_count(ud, y);

        double lrr = pascal[lr][lrc.first];
        double udr = pascal[ud][udc.first];
        double hvr = pascal[n][lr];

        double now = lrr * udr * hvr;
        ans += now;

    }

    printf("%.20f\n", ans);

}
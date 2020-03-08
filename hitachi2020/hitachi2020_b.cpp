#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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


struct Voucher {
    int refrigerator, microwaves;
    int price;
};

int main() {
    int a, b, m;
    cin >> a >> b >> m;

    vector<int> refrigerators(a), microwaves(b);
    rep(i, a) cin >> refrigerators[i];
    rep(i, b) cin >> microwaves[i];

    vector<Voucher> vouchers(m);

    rep(i, m) cin >> vouchers[i].refrigerator >> vouchers[i].microwaves >> vouchers[i].price;
    rep(i, m) vouchers[i].refrigerator--;
    rep(i, m) vouchers[i].microwaves--;

    int min_price_refrigerator = *min_element(refrigerators.begin(), refrigerators.end());
    int min_price_microwave = *min_element(microwaves.begin(), microwaves.end());

    int min_price = min_price_refrigerator + min_price_microwave;
    for (Voucher &v  : vouchers) {
        int now = refrigerators[v.refrigerator] + microwaves[v.microwaves] - v.price;
        cmin(min_price, now);
    }


    cout << min_price << endl;
}

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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


struct Lottery {
    int cost;
    vector<ll> rates;

    Lottery(int n) : rates(n) {}


};

std::istream &operator>>(std::istream &in, Lottery &o) {
    int count;
    cin >> count;
    cin >> o.cost;
    rep(i, count) {
        int idol;
        cin >> idol;
        idol--;
        cin >> o.rates[idol];
    }
    return in;
}


int main() {
    int n, m;
    cin >> n >> m;

    assert(n == 1);

    vector<Lottery> lotteries(m, Lottery(n));

    rep(i, m)cin >> lotteries[i];

    Lottery ans = *min_element(lotteries.begin(), lotteries.end(),[](Lottery &l1, Lottery &l2){
        return l1.cost < l2.cost;
    });

    cout << ans.cost << endl;

}

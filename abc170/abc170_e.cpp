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


ll ma(multiset<ll> &s) {
    auto it = s.end();
    it--;
    return *it;

}

ll mi(multiset<ll> &s) {
    auto it = s.begin();
    return *it;
}


int main() {

    const int ALL = 2e5 + 10;

    multiset<ll> heights;

    map<ll, ll> infants_in; // [園児] = 保育園
    map<ll, ll> infants_rate; // [園児] = レート
    vector<multiset<ll>> kindergartens(ALL);


    int n, q;
    cin >> n >> q;


    rep(i, n) {
        int rate, kindergarten;
        cin >> rate >> kindergarten;

        int infant = i + 1;

        infants_rate[infant] = rate;
        kindergartens[kindergarten].insert(rate);
        infants_in[infant] = kindergarten;
    }

    rep(i, ALL) {
        if (!kindergartens[i].empty()) heights.insert(ma(kindergartens[i]));
    }


    auto del = [&](multiset<ll> &s, ll l) {
        heights.erase(heights.find(ma(s)));
        s.erase(s.find(l));
        if (!s.empty()) heights.insert(ma(s));
    };

    auto insert = [&](multiset<ll> &s, ll l) {
        if (!s.empty())heights.erase(heights.find(ma(s)));
        s.insert(l);
        heights.insert(ma(s));
    };

    auto print = [&]() {
        cout << mi(heights) << endl;
    };

    rep(_, q) {
        int infant, to;
        cin >> infant >> to;
        int rate = infants_rate[infant];
        int from = infants_in[infant];

        del(kindergartens[from], rate);
        insert(kindergartens[to], rate);

        infants_in[infant] = to;
        print();

    }


}
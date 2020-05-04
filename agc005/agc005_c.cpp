#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];

    int ma = *max_element(numbers.begin(), numbers.end());

    multiset<int> ps;
    for (int i : numbers) ps.insert(i);

    rep(i, ma + 1) {
        int j = max(i, ma - i);
        auto it = ps.find(j);
        if (it == ps.end()) {
            cout << "Impossible" << endl;
            ret();
        }
        ps.erase(it);
    }

    for (int i : ps) {
        int b = ma % 2 == 0 ? ma / 2 + 1 : (ma + 1) / 2 + 1;
        if (i >= b) continue;
        cout << "Impossible" << endl;
        ret();
    }
    cout << "Possible" << endl;

}

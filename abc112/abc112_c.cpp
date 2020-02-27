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

struct Hint {
    int x, y, h;
};

ll check(int x, int y, vector<Hint> &hints) {

    vector<ll> over;
    vector<ll> match;

    for (Hint hint : hints) {
        if (hint.h == 0) {
            ll md = abs(hint.x - x) + abs(hint.y - y);
            ll h = hint.h + md;
            over.push_back(h);
        } else {
            ll md = abs(hint.x - x) + abs(hint.y - y);
            ll h = hint.h + md;
            match.push_back(h);
        }
    }

    assert(!match.empty());

    ll ma = *max_element(match.begin(), match.end());
    ll mi = *min_element(match.begin(), match.end());
    if (ma != mi) return -1;

    for (ll o : over) if (o < ma) return -1;
    return ma;
}

int main() {
    int n;
    cin >> n;

    vector<Hint> hints(n);
    rep(i, n) cin >> hints[i].x >> hints[i].y >> hints[i].h;

    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            ll h = check(x, y, hints);
            if (h != -1) {
                printf("%d %d %lld\n", x, y, h);
            }
        }
    }
}
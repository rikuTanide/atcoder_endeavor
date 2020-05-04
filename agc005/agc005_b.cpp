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
    rep(i, n) cin >> numbers[i], numbers[i]--;

    vector<int> indexes(n);
    rep(i, n) indexes[numbers[i]] = i;

    set<int> used;

    ll ans = 0;
    rep(i, n) {
        int index = indexes[i];
        int end = [&] {
            auto end_it = used.upper_bound(index);
            if (end_it == used.end()) return n;
            return *end_it;
        }();
        int start = [&] {
            auto begin_it = used.upper_bound(index);
            if (begin_it == used.begin()) return -1;
            begin_it--;
            return *begin_it;
        }();
        used.insert(index);

        ll r = end - index;
        ll l = index - start;

        ll k = r * l;

        ll p = k * (i + 1);

        ans += p;
    }
    cout << ans << endl;

}

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

bool check(vector<int> &v) {
    vector<int> u = v;
    sort(u.begin(), u.end());
    return u == v;
}

void add(vector<int> &t, vector<int> &s, int i) {
    if (s.size() > i) t.push_back(s[i]);
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int n = a + b + c;

    vector<int> arr(n);
    rep(i, n)arr[i] = i;
    int ans = 0;
    do {

        bool ok = [&]() -> bool {
            queue<int> q;
            for (int e : arr) q.push(e);
            vector<vector<int>> t(3);
            rep(i, a) t[0].push_back(q.front()), q.pop();
            rep(i, b) t[1].push_back(q.front()), q.pop();
            rep(i, c) t[2].push_back(q.front()), q.pop();

            rep(i, 3)if (!check(t[i])) return false;

            rep(i, 3) {
                vector<int> s;
                add(s, t[0], i);
                add(s, t[1], i);
                add(s, t[2], i);

                if (!check(s)) return false;

            }
            return true;
        }();

        if (ok) ans++;
    } while (std::next_permutation(arr.begin(), arr.end()));
    cout << ans << endl;
}

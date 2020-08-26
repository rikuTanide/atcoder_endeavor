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
    int n, x;
    cin >> n >> x;

    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
        ret();
    }

    queue<int> q;
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (i == x || i - 1 == x || i + 1 == x) {
            continue;
        }
        q.push(i);
    }

    deque<int> ans;
    ans.push_back(x - 1);
    ans.push_back(x);
    ans.push_back(x + 1);
    while (!q.empty()) {
        ans.push_front(q.front());
        q.pop();
        ans.push_back(q.front());
        q.pop();
    }

    cout << "Yes" << endl;
    while (!ans.empty()) {
        cout << ans.front() << endl;
        ans.pop_front();
    }


}

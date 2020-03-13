#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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

struct Q {
    ll left, right, prod;
};

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    if (find(numbers.begin(), numbers.end(), 0) != numbers.end()) {
        cout << n << endl;
        ret();
    }

    queue<Q> q;
    q.push({0, 0, numbers.front()});

    ll ans = 0;
    while (!q.empty()) {
        Q p = q.front();
        q.pop();

        if (p.prod <= k) {
            ll now = p.right - p.left + 1;
            cmax(ans, now);

            if (p.right < n - 1) {
                q.push({p.left, p.right + 1, p.prod * numbers[p.right + 1]});
            }

        } else {
            if (p.left == p.right) {
                if (p.left < n - 1) {
                    q.push({p.left + 1, p.right + 1, numbers[p.left + 1]});
                }
            } else {
                assert(p.prod % numbers[p.left] == 0);
                q.push({p.left + 1, p.right, p.prod / numbers[p.left]});
            }
        }
    }
    cout << ans << endl;

}

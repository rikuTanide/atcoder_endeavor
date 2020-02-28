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

struct Level {
    ll pate, ban, total;
};

const Level ban = {0, 1, 1},
        pate = {1, 0, 1};

vector<Level> searchBound(int depth, vector<Level> &levels, ll n, ll x) {
    Level l = levels[n - depth];
    if (l.total < x) return {l};
    else {
        Level next = levels[n - depth - 1];
        // ban, next, pate, next, ban

        vector<Level> res;
        ll sum = 0;
        if (x == 0) return res;
        sum += 1;
        res.push_back(ban);
        if (x == sum) return res;
        if (sum + next.total >= x) {
            vector<Level> k = searchBound(depth + 1, levels, n, x - sum);
            for (Level m : k) res.push_back(m);
            return res;
        } else {
            sum += next.total;
            res.push_back(next);
        }
        sum++;
        res.push_back(pate);
        if (x == sum) return res;
        if (sum + next.total >= x) {
            vector<Level> k = searchBound(depth + 1, levels, n, x - sum);
            for (Level m : k) res.push_back(m);
            return res;
        } else {
            sum += next.total;
            res.push_back(next);
        }
        sum++;
        res.push_back(ban);
        if (x == sum) return res;

        __throw_runtime_error("konai");
    }
}

int main() {
    ll n, x;
    cin >> n >> x;

    vector<Level> levels(n + 1);
    levels[0].ban = 0;
    levels[0].pate = 1;
    levels[0].total = 1;
    for (int i = 1; i <= n; i++) {
        levels[i].pate = 1 + levels[i - 1].pate + levels[i - 1].pate;
        levels[i].ban = 2 + levels[i - 1].ban + levels[i - 1].ban;
        levels[i].total = levels[i].pate + levels[i].ban;
    }

    vector<Level> res = searchBound(0, levels, n, x);
    ll ans = 0;
    for (Level r : res) {
        ans += r.pate;
    }
    cout << ans << endl;

}
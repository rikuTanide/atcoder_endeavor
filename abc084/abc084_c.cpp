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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

struct Train {
    ll time, start, between;
};

int main() {
    int n;
    cin >> n;

    vector<Train> trains(n - 1);
    rep(i, n - 1) cin >> trains[i].time >> trains[i].start >> trains[i].between;

    for (int j = 0; j < n - 1; j++) {

        ll now = 0;
        for (int i = j; i < n - 1; i++) {
            Train t = trains[i];
            if (now <= t.start) {
                now = t.start + t.time;
                continue;
            }
            ll honme = (now + t.between - 1) / t.between;
            ll start = honme * t.between;
            now = start + t.time;
        }
        cout << now << endl;
    }
    cout << 0 << endl;
}
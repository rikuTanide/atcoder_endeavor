#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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

struct Attack {
    int attack, magic_point;
};

int main() {
    int h, n;
    cin >> h >> n;

    vector<Attack> attacks(n);
    rep(i, n) cin >> attacks[i].attack >> attacks[i].magic_point;

    vector<int> stamina(h + 1, INT_MAX);
    stamina[0] = 0;

    auto set = [&](int now, int attack, int magic_point) {
        int next = now + attack;
        int now_magic_point = stamina[now];
        if (now_magic_point == INT_MAX) return;
        if (next > h) {
            next = h;
        }
        if (now_magic_point + magic_point >= stamina[next]) {
            return;
        }
        stamina[next] = now_magic_point + magic_point;
    };

    for (int i = 0; i <= h; i++) {
        for (Attack &a : attacks) {
            set(i, a.attack, a.magic_point);
        }
    }

    cout << stamina.back() << endl;

}

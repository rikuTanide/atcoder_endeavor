#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void update(int x, int y, map<vector<int>, P> &mp) {
    rep(i, 4) {
        if (mp.find({x, y, i}) == mp.end()) {
            mp[{x, y, i}] = {x + dx[i], y + dy[i]};
        }
    }

    rep(i, 4) {
        P p = mp[{x, y, i}];
        mp[{p.first, p.second, (i + 2) % 4}] = mp[{x, y, (i + 2) % 4}];
    }


}


int main() {
    int n;
    string s;
    cin >> n >> s;
    map<vector<int>, P> mp;

    update(0, 0, mp);

    int x = 0, y = 0;

    rep(i, n) {
        char c = s[i];
        int d = [](char c) {
            switch (c) {
                case 'R':
                    return 0;
                case 'D' :
                    return 1;
                case 'L':
                    return 2;
                case 'U':
                    return 3;
            }
            __throw_runtime_error("konai");
        }(c);

        P p = mp[{x, y, d}];
        x = p.first;
        y = p.second;
        update(p.first, p.second, mp);
    }

    cout << x << ' ' << y << endl;

}

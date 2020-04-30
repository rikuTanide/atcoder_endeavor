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

typedef pair<int, int> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Rabbit {
    ll x;
    char direction;
};

struct Range {
    ll start, end;
    vector<int> rights, lefts;
};

int main() {
    int n, l;
    cin >> n >> l;

    vector<Rabbit> rabbits(n);
    rep(i, n) cin >> rabbits[i].x >> rabbits[i].direction, rabbits[i].x--;

    vector<int> behinds(n, 0);
    rep(i, n) {
        if (i == 0) continue;
        if (rabbits[i - 1].direction == 'R' && rabbits[i].direction == 'R') behinds[i] = behinds[i - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--) {
        if (rabbits[i].direction == 'L' && rabbits[i + 1].direction == 'L') behinds[i] = behinds[i + 1] + 1;
    }

    ll ans = 0;
    rep(i, n - 1) {
        if (rabbits[i].direction == 'R' && rabbits[i + 1].direction == 'L') {
            if (behinds[i] < behinds[i + 1]) {
                ll old = rabbits[i + 1].x;
                rabbits[i + 1].x = rabbits[i].x + 1;
                ll distance = abs(old - rabbits[i + 1].x);
                ans += distance;
            } else {
                ll old = rabbits[i].x;
                rabbits[i].x = rabbits[i + 1].x - 1;
                ll distance = abs(old - rabbits[i].x);
                ans += distance;
            }
        }
    }

    rep(i, n) {
        if (rabbits[i].direction == 'L') {
            ll front = i == 0 ? -1 : rabbits[i - 1].x;
            ll old = rabbits[i].x;
            rabbits[i].x = front + 1;
            ll distance = abs(old - rabbits[i].x);
            ans += distance;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (rabbits[i].direction == 'R') {
            ll front = i == n - 1 ? l : rabbits[i + 1].x;
            ll old = rabbits[i].x;
            rabbits[i].x = front - 1;
            ll distance = abs(old - rabbits[i].x);
            ans += distance;
        }
    }


    cout << ans << endl;

}

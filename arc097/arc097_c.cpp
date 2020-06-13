#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
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

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Ball {
    int v;
    char c;
};

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return sums.back();
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

int main() {
    int n;
    cin >> n;

    vector<Ball> balls(2 * n);
    rep(i, 2 * n) cin >> balls[i].c >> balls[i].v;

    map<P, ll> m;

    map<int, int> bi, wi;
    rep(i, 2 * n) if (balls[i].c == 'B') bi[balls[i].v] = i; else wi[balls[i].v] = i;

    m[P(0, 0)] = 0;


    auto get_index = [&](char c, int v) {
        if (c == 'B') return bi[v];
        else return wi[v];
    };


    vector<CumulativeSum> bcs(n + 1, CumulativeSum(2 * n)), wcs(n + 1, CumulativeSum(2 * n));

    // 黒
    rep(i, n + 1) {
        rep(j, n + 1) {
            if (j <= i) continue;
            bcs[i].set(bi[j], 1);
        }
    }
    rep(i, n + 1) bcs[i].calculate();
    // 白
    rep(i, n + 1) {
        rep(j, n + 1) {
            if (j <= i) continue;
            wcs[i].set(wi[j], 1);
        }
    }
    rep(i, n + 1) wcs[i].calculate();

    auto get_lager = [&](int r, char c, int v) -> ll {

        if (c == 'B')return bcs[v].getSum(r - 1);
        return wcs[v].getSum(r - 1);

    };

    auto set = [&](int b, int w, ll value) {
        P index(b, w);
        if (m.find(index) == m.end()) m[index] = value;
        else
            cmin(m[index], value);
    };

    for (ll b = 0; b <= n; b++) {
        for (ll w = 0; w <= n; w++) {

            assert(m.find(P(b, w)) != m.end());
            ll prev = m[P(b, w)];
            {

                // 黒を足す
                ll nb = b + 1;
                ll nw = w;

                if (nb <= n) {

                    ll i = get_index('B', nb);
                    ll lb = get_lager(i, 'B', nb);
                    ll lw = get_lager(i, 'W', nw);


                    ll now = prev + lb + lw;
                    set(nb, nw, now);
                }
            }
            {
                // 白を足す
                ll nw = w + 1;
                ll nb = b;

                if (nw <= n) {
                    ll i = get_index('W', nw);
                    ll lw = get_lager(i, 'W', nw);
                    ll lb = get_lager(i, 'B', nb);
                    ll now = prev + lb + lw;
                    set(nb, nw, now);
                }
            }

        }
    }

//    rep(y, n) {
//        rep(x, n) {
//            cout << m[P(y, x)] << ' ';
//        }
//        cout << endl;
//    }

    cout << m[P(n, n)] << endl;

}
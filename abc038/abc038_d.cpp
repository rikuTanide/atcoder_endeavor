#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Bit {
    int64_t size;
    vector<int64_t> v;

    Bit(int64_t n) : size(n + 1), v(size) {}

    void update(int64_t a, int64_t w) {
        for (int64_t x = a; x <= size; x += x & -x) v[x] = max(w, v[x]);
    }

    int query(int64_t a) {
        int64_t res = 0;
        for (int64_t x = a; x > 0; x -= x & -x) res = max(res, v[x]);
        return res;
    }
};

struct Box {
    int width, height;
};

int main() {
    int n;
    cin >> n;


    vector<Box> boxes(n);
    rep(i, n) {
        int w, h;
        cin >> w >> h;

        boxes[i].width = w;
        boxes[i].height = h;
    }

    sort(boxes.begin(), boxes.end(), [](Box &b, Box &c) {
        if (b.width == c.width) {
            return b.height > c.height;
        }
        return b.width < c.width;
    });

    int max_h = accumulate(boxes.begin(), boxes.end(), 0, [](int m, Box &c) {
        return max(m, c.height);
    });

    Bit bit(max_h);

    for (Box &box : boxes) {
        bit.update(box.height, bit.query(box.height - 1) + 1);
    }

    cout << bit.query(max_h) << endl;

}
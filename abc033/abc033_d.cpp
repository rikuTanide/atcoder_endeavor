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
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Point {
    int x, y;
};

struct Angle {
    int x, y;
    double tan;
};

int main() {
    ll n;
    cin >> n;
    vector<Point> points(n);

    rep(i, n) {
        cin >> points[i].x;
        cin >> points[i].y;
    }

    ll chokaku_count = 0;
    ll donkaku_count = 0;

    double pi = atan2(0.0, -1.0);

    rep(i, n) {
        // iを中心としたときの各頂点のatan2

        int cx = points[i].x;
        int cy = points[i].y;

        vector<Angle> angles((n - 1) * 2);

        rep(j, n) {
            if (i == j) {
                angles[j].tan = pi * 3;
                continue;
            }
            int x = points[j].x;
            int y = points[j].y;
            x -= cx;
            y -= cy;
            double t = atan2((double) y, (double) x);

            angles[j].x = x;
            angles[j].y = y;
            angles[j].tan = t;

        }

        sort(angles.begin(), angles.begin() + n, [](Angle &a, Angle &b) {
            return a.tan < b.tan;
        });

        for (int j = 0; j < n - 1; j++) {
            angles[j + (n - 1)].x = angles[j].x;
            angles[j + (n - 1)].y = angles[j].y;
            angles[j + (n - 1)].tan = angles[j].tan + (2 * pi);
        }

        auto getShogen = [&](int x, int y) {
            if (0 <= x && 0 < y) {
                return 1;
            }
            if (x < 0 && 0 <= y) {
                return 2;
            }
            if (y < 0 && x <= 0) {
                return 3;
            }
            if (0 < x && y <= 0) {
                return 4;
            }

            __throw_runtime_error("nai");
        };

        auto isChokkaku = [&](int a, int b) {
            int ax = angles[a].x;
            int ay = angles[a].y;
            int bx = angles[b].x;
            int by = angles[b].y;

            int as = getShogen(ax, ay);
            int bs = getShogen(bx, by);
            if (as == 1 && bs != 4) return false;
            if (as == 2 && bs != 1) return false;
            if (as == 3 && bs != 2) return false;
            if (as == 4 && bs != 3) return false;

            return (ax * bx + ay * by) == 0;
        };

        auto isEikaku = [&](int a, int b) {
            return angles[a].tan - angles[b].tan < (pi / 2);
        };

        auto isDonkaku = [&](int a, int b) {
            return angles[a].tan - angles[b].tan < pi;
        };

        int front_90 = 0;
        int front_180 = 0;
        for (int back = 0; back < n - 1; back++) {
            while ((!isChokkaku(front_90, back)) && isEikaku(front_90, back)) {
                front_90++;
            }
            front_180 = front_90;
            while (isDonkaku(front_180, back)) {
                front_180++;
            }
            donkaku_count += front_180 - front_90;
            if (isChokkaku(front_90, back)) {
                chokaku_count++;
                donkaku_count--;
            }else {
                int a = 0;
            }
        }

    }

    ll eikaku = n * (n - 1) * (n - 2) / 6 - donkaku_count - chokaku_count;

    cout << eikaku << ' ' << chokaku_count << ' ' << donkaku_count << endl;

}
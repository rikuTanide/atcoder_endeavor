#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e15;
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

const int column = 50;

struct Solution {
    double water, sugar;

    double rate() {
        return (100 * sugar) / (water + sugar);
    }
};

int main() {
    double w1, w2, s1, s2, mr, b;
    cin >> w1 >> w2 >> s1 >> s2 >> mr >> b;

    w1 *= 100;
    w2 *= 100;

    set<double> sugars;
    for (int s1i = 0; s1i * s1 <= b; s1i++) {
        for (int s2i = 0; (s1i * s1) + (s2i * s2) <= b; s2i++) {
            sugars.insert(s1 * s1i + s2 * s2i);
        }
    }

    auto check_rate = [&](double w) {
        double b = w * mr / 100;
        auto it = sugars.upper_bound(b);
        assert(it != sugars.begin());
        it--;
        double l = *it;
        assert((100 * l) / (w + l) <= mr);
        return l;
    };

    auto check_b = [&](double w) {
        double nokori = b - w;
        assert(nokori >= 0);
        auto it = sugars.upper_bound(nokori);
        if (it == sugars.begin()) return 0.0;
        it--;
        double l = *it;
        assert(w + l <= b);
        return l;
    };

    vector<Solution> solutions;

    for (int w1i = 0; w1i * w1 <= b; w1i++) {
        for (int w2i = 0; w1i * w1 + w2i * w2 <= b; w2i++) {
            if (w1i == 0 && w2i == 0) continue;
            double w = w1i * w1 + w2i * w2;
            double s_r = check_rate(w);
            double r_b = check_b(w);
            double now = min(s_r, r_b);
            solutions.push_back(Solution{w, now});
        }
    }


    sort(solutions.rbegin(), solutions.rend(), [](Solution &s, Solution &t) {
        return s.rate() < t.rate();
    });
    Solution s = solutions.front();
//    Solution s = *max_element(solutions.begin(), solutions.end(), [](Solution &s, Solution &t) {
//        return s.rate() < t.rate();
//    });

    assert(s.water + s.sugar <= b);
    assert(s.water * mr / 100 >= s.sugar);
    cout << s.water + s.sugar << ' ' << s.sugar << endl;

}


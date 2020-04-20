#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

const int mod = 1000000007;
struct Solution {
    double water, salt;
};

struct Staging {
    int solution_index;
    double concentration;
    Solution next;
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<Solution> solutions(n);

    rep(i, n) {
        double a, b;
        cin >> a >> b;
        double salt = b / 100 * a;
        double water = a - salt;
        solutions[i].water = water;
        solutions[i].salt = salt;
    }

    Solution current = {0, 0};

    auto next = [&](Solution current) {

        vector<Staging> staging(solutions.size());

        rep(i, solutions.size()) {
            Solution solution = solutions[i];
            staging[i].solution_index = i;
            staging[i].next = {current.water + solution.water, current.salt + solution.salt};
            staging[i].concentration = staging[i].next.salt / (staging[i].next.water + staging[i].next.salt);

        }

        sort(staging.rbegin(), staging.rend(), [](Staging s, Staging t) { return s.concentration < t.concentration; });
        return staging.front();
    };

    rep(i, k) {
        Staging t = next(current);
        current = t.next;
        solutions.erase(solutions.begin() + t.solution_index);
    }

    double a = current.salt / (current.salt + current.water) * 100;
    printf("%.20f\n", a);

}

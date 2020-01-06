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

struct Solution {
    double concentration, solution, salt, water;
};

int main() {

    int n, k;
    cin >> n >> k;

    vector<Solution> solutions(n);
    set<int> candidates;

    rep(i, n) {
        double w, p;
        cin >> w >> p;
        double salt = w * p / 100;
        double water = w - salt;

        Solution solution{p, w, salt, water};
        solutions[i] = solution;
        candidates.insert(i);
    }

    double now_water = 0, now_concentration = 0, now_salt = 0, now_solution = 0;


    for (int i = 0; i < k; i++) {

        double nc = 0;
        int l = 0;

        for (int j : candidates) {
            Solution s = solutions[j];
            double water = now_water + s.water;
            double solution = now_solution + s.solution;
            double salt = now_salt + s.salt;
            double concentration = salt / solution;
            if (nc < concentration) {
                nc = concentration;
                l = j;
            }
        }
        now_water += solutions[l].water;
        now_salt += solutions[l].salt;
        now_solution = now_water + now_salt;
        candidates.erase(l);
    }
    double ans = now_salt / now_solution * 100;
    printf("%.10f\n", ans);

}
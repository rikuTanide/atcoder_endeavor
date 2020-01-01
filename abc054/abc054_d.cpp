#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX;
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
    int a, b, c;
};


Solution solutionSum(vector<Solution> &solutions) {
    int costs = accumulate(solutions.begin(), solutions.end(), 0, [](int a, Solution b) {
        return a + b.c;
    });
    int a = accumulate(solutions.begin(), solutions.end(), 0, [](int a, Solution b) {
        return a + b.a;
    });
    int b = accumulate(solutions.begin(), solutions.end(), 0, [](int a, Solution b) {
        return a + b.b;
    });

    return Solution{a, b, costs};
}

class Knapsack {
    vector<vector<vector<int>>> knapsack;
    vector<Solution> &candidates;
public:
    Knapsack(vector<Solution> &candidates) : candidates(candidates) {
        Solution sum = solutionSum(candidates);
        knapsack.resize(candidates.size(), vector<vector<int>>(sum.a + 1, vector<int>(sum.b + 1, INF)));
        knapsack[0][0][0] = 0;
    }

    int getBefore(int i, int a, int b) {
        if (i == -1 && a == 0 && b == 0) return 0;
        if (i == -1) return INF;
        return knapsack[i][a][b];
    }

    int calculate(int a, int b) {
        for (int i = 0; i < candidates.size(); i++) {
            Solution c = candidates[i];

            for (int a = 0; a < knapsack[i].size(); a++) {
                for (int b = 0; b < knapsack[i][a].size(); b++) {
                    int before_cost = getBefore(i - 1, a, b);
                    if (before_cost == INF) continue;
                    knapsack[i][a][b] = min(knapsack[i][a][b], before_cost);
                }
            }

            for (int a = 0; a < knapsack[i].size(); a++) {
                for (int b = 0; b < knapsack[i][a].size(); b++) {
                    int before_cost = getBefore(i - 1, a, b);
                    if (before_cost == INF) continue;
                    int new_cost = before_cost + c.c;
                    int next_a = a + c.a;
                    int next_b = b + c.b;
                    int old = knapsack[i][next_a][next_b];
                    knapsack[i][next_a][next_b] = min(old, new_cost);
                }
            }

        }

        int i = 1;
        int a_i = a;
        int b_i = b;

        int ans = INF;
        while (a_i < knapsack.back().size() && b_i < knapsack.back()[a].size()) {
            cmin(ans, knapsack.back()[a_i][b_i]);
            i++;
            a_i = a * i;
            b_i = b * i;
        }
        return ans;
    }

};

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;

    vector<Solution> solution_list;

    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution solution{a, b, c};

        solution_list.push_back(solution);
    }

    Knapsack knapsack(solution_list);
    int ans = knapsack.calculate(ma, mb);
    if (ans == INF) ans = -1;
    cout << ans << endl;


}


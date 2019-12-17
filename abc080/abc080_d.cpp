#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
//typedef pair<int, int> P;

struct Program {
    int start, end, channel;

    bool operator<(const Program &another) const {
        return start < another.start;
    };
};

typedef pair<int, char> P;

int main() {


    int n, c;
    cin >> n >> c;
    vector<vector<Program>> tmp_programs(c);

    rep(i, n) {
        int si, ti, ci;
        cin >> si >> ti >> ci;
        ci--;
        si--;
        ti--;
        Program p = {si, ti, ci};
        tmp_programs[ci].push_back(p);
    }
    vector<vector<Program>> programs(c);

    rep(ci, c) {
        if (tmp_programs[ci].empty()) continue;
        sort(tmp_programs[ci].begin(), tmp_programs[ci].end());

        programs[ci].push_back(tmp_programs[ci][0]);

        for (int i = 1; i < tmp_programs[ci].size(); i++) {
            if ((tmp_programs[ci][i].start - programs[ci].back().end) <= 3) {
                programs[ci].back().end = tmp_programs[ci][i].end;
            } else {
                programs[ci].push_back(tmp_programs[ci][i]);
            }
        }
    }
    vector<P> all;
    rep(ci, c) {
        for (Program p : programs[ci]) {
            // 重複の場合は2台いるからSが先
            all.push_back(P(p.start, 'S'));
            all.push_back(P(p.end, 'E'));
        }
    }

    sort(all.begin(), all.end());

    int ans = 0;
    int now = 0;

    for (P p : all) {
        if (p.second == 'E') {
            now--;
        } else {
            now++;
            cmax(ans, now);
        }

    }

    cout << ans << endl;

}

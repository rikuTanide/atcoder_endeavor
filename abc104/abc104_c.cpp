#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
const double INF = 1e10;
//const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
typedef tuple<int, int, int> Q;

int main() {
    int d, g;
    cin >> d >> g;

    vector<Q> questions(d);//i, 問題数, ボーナス

    rep(i, d) {
        int p, c;
        cin >> p >> c;
        Q q(i + 1, p, c);
        questions[i] = q;
    }

    map<int, int> ok_i;

    for (int pattern = 0; pattern < (1 << d); pattern++) {
        // 最大値

        int max_points = [&] {
            int ans = 0;
            for (int i = 0; i < d; i++) {
                auto q = questions[i];
                int baisu = get<0>(q) * 100;
                int mondaisu = get<1>(q);
                int bonus = get<2>(q);
                int a = (pattern >> i) & 1;
                if (a == 1) {
                    ans += baisu * mondaisu + bonus;
                } else {
                    ans += baisu * (mondaisu - 1);
                }
            }
            return ans;
        }();

//        cout << bitset<8>(pattern) << ' ' << max_points << endl;

        if (max_points >= g) {
            ok_i[pattern] = max_points;
        }

    }

    int ans = INF;
    for (auto m : ok_i) {
        int pattern = m.first;
        int point = m.second;
        int question_count = 0;

        vector<int> herasite_iiyatsu; // 減らしていい奴、得点が低い順

        for (int j = 0; j < d; j++) {
            int a = (pattern >> j) & 1;
            if (a == 0) {
                herasite_iiyatsu.push_back(j);
                int mondaisu = get<1>(questions[j]);
                question_count += mondaisu - 1;
            } else {
                int mondaisu = get<1>(questions[j]);
                question_count += mondaisu;
            }
        }

        int now = [&] {
            int now = point;
            int qc = question_count;

            for (int herasuyatsu : herasite_iiyatsu) {
                int mondaisu = get<1>(questions[herasuyatsu]) ;
                int tokuten = (herasuyatsu + 1) * 100;
                for (int nokori = 0; nokori < mondaisu - 1; nokori++) {
                    if ((now - tokuten) < g) {
                        return qc;
                    } else {
                        now -= tokuten;
                        qc--;
                    }
                }
            }
            return qc;

        }();
        ans = min(ans, now);
    }
    cout << ans << endl;
}

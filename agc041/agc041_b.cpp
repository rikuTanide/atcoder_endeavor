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
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
//const int mod = 1000000007;
const ll mod = INF / 1000;

bool check(int candidate, vector<ll> &points, int voting_count, int task_count, ll judge_count) {
    if (candidate < task_count) return true;
    ll border = points[task_count];
    ll me = points[candidate];
    ll me_max = me + judge_count;
    if (me_max < border) return false;

    voting_count--; // 自分に
    ll strong = (task_count - 1);// 入れるから
    voting_count -= strong; // 既に当確の奴に全部入れる
    int weak = points.size() - candidate - 1; // 自分より弱い奴にはいくら上げてもいい
    voting_count -= weak;

    if (voting_count <= 0) return true;

    ll all_voting_count = judge_count * voting_count;

    for (int t = task_count; t < candidate; t++) {
        ll capacity = me_max - points[t]; // 受け入れられる票数
        if (capacity >= judge_count) {
            all_voting_count -= judge_count;
        } else {
            all_voting_count -= capacity;
        }
    }

    return all_voting_count <= 0;
}


int main() {

    int n, v, p;
    ll m;
    cin >> n >> m >> v >> p;

    vector<ll> points(n);

    rep(i, n) cin >> points[i];
    sort(points.rbegin(), points.rend());

    // 当落線

    int ceil = n - 1;
    int floor = 0;

    if(check(ceil, points, v, p, m)) {
        cout << n << endl;
        return 0;
    }

    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        if (check(mid, points, v, p, m)) {
            floor = mid;
        } else {
            ceil = mid;
        }
    }

    cout << ceil << endl;

}

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

struct Task {
    ll next;
    ll cost; // 0か1
    ll prev_cost; // ここまでのコストの累積
};

void insertTask(ll i, ll current_cost, ll k, vector<bool> &visited, deque<Task> &q) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;


    // 10倍
    {
        ll next = (i * 10) % k;
        Task t = {next, 0, current_cost};
        q.push_front(t);
    }
    // +1
    {
        ll next = (i + 1) % k;
        Task t = {next, 1, current_cost};
        q.push_back(t);
    }

}

ll dfs(ll k) {

    vector<bool> visited(k);
    deque<Task> q;
    Task first = {1, 0, 0};
    q.push_back(first);

    while (!q.empty()) {
        Task t = q.front();
        q.pop_front();

        if (t.next == 0) {
            return t.prev_cost + t.cost;
        }
        insertTask(t.next, t.prev_cost + t.cost, k, visited, q);
    }
    return -1;
}

int main() {

    ll k;
    cin >> k;


    ll ans = dfs(k);
    cout << ans + 1 << endl;
}

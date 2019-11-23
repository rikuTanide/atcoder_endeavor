#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

vector<P> bridges;
vector<set<int>> groups;
vector<ll> ans;
int n = 0;

ll countAns() {
    int a = 0;
    for (auto g : groups) {
        ll igai = n - g.size();
        ll ikenai = igai * g.size();
        a += ikenai;
    }
    return a / 2;
}

int findGroup(int i) {
    // ここが間に合わなかったらmapにする
    for (int j = 0; j < groups.size(); j++) {
        auto group = groups[j];
        auto it = group.find(i);
        if (it == group.end()) continue;
        return j;
    }
    return -1;
}

int main() {
    int m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bridges.emplace_back(a, b);
    }
    // 1番目から順に崩落するということは、
    // m番目から順に建築されるのと同義
    reverse(bridges.begin(), bridges.end());

    // 最初にすべての島は独立している
    for (int i = 0; i < n; i++) {
        set<int> group;
        group.insert(i);
        groups.push_back(group);
    }

    for (int i = 0; i < m; i++) {
        auto bridge = bridges[i];

        int firstGroupIndex = findGroup(bridge.first);
        auto firstGroup = &groups[firstGroupIndex];
        int secondGroupIndex = findGroup(bridge.second);
        auto secondGroup = &groups[secondGroupIndex];
        if (firstGroup == secondGroup) {
//            ans.push_back(countAns());
            continue;
        }
        firstGroup->insert(secondGroup->begin(), secondGroup->end());
        groups.erase(groups.begin() + secondGroupIndex);
//        ans.push_back(countAns());
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << endl;
    }
    cout << n * (n - 1) / 2 << endl;

}


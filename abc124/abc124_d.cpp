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

typedef pair<int, char> PC;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<PC> seq_counts;
    char prev = s[0];
    int seq = 1;
    for (int i = 1; i < s.size(); i++) {
        char now = s[i];
        if (now != prev) {
            seq_counts.emplace_back(seq, prev);
            prev = now;
            seq = 1;
        } else {
            seq++;
        }
    }
    seq_counts.emplace_back(seq, prev);

    queue<PC> left;
    queue<PC> center;
    queue<PC> right;

    for (auto p : seq_counts) {
        right.push(p);
    }

    int count = 0;
    int ans = 0;
    int c_count = 0; // 直立カウント
    while (!right.empty()) {
        auto next = right.front(); // 次に入れたい
        if (next.second == '1') {
            right.pop();
            center.push(next);
            count += next.first;
            ans = max(ans, count);
            continue;
        }
        // 次に入れたいのは直立

        if (c_count == k) {
            // 一番左だけ取り出せばいい時と、二回連続で取り出さないといけないと気があるが、
            // whileで上手くいく
            auto pop = center.front();
            if (pop.second == '1') {
                center.pop();
                count -= pop.first;
                continue;
            } else {
                center.pop();
                count -= pop.first;
                c_count--;
                continue;
            }
        }

        right.pop();
        center.push(next);
        count += next.first;
        ans = max(ans, count);
        c_count++;

    }

    cout << ans << endl;

}


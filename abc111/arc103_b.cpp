#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\01.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;

vector<P> targets;

bool checkEnability() {
    bool odd = false, even = false;

    for (P p : targets) {
        ll o = (p.first + p.second) % 2;
        if (o == 0) {
            even = true;
        } else {
            odd = true;
        }
    }

    if (even && odd) {
        return false;
    }
    return true;
}

// ある点がn乗の範囲内に収まるか
int checkOddInner(int n, ll x, ll y) {
    ll boundary = (1ll << n) - 1;
    if (abs(x) + abs(y) <= boundary) {
        return true;
    }
    return false;
}

int maxOddArmCount() {
    int ans = 0;
    for (P p : targets) {
        for (int i = 1; i < 40; i++) {
            if (checkOddInner(i, p.first, p.second)) {
                ans = max(ans, i);
                break;
            }
        }
    }
    return ans;
}

void culcOdd() {

    // ある点を含む最小の2のn乗
    // 奇数の時だけ考える

    int max_arm_count = maxOddArmCount();

    cout << max_arm_count << endl;

    for (int i = 1; i <= max_arm_count; i++) {
        cout << (1ll << (i - 1)) << ' ';
    }
    cout << endl;


    for (P p : targets) {

        string ans = "";
        ll prev_x = p.first;
        ll prev_y = p.second;
        for (int i = (max_arm_count - 1); i >= 0; i--) {
            ll arm_length = 1ll << i;
            // U
            {
                ll x = prev_x;
                ll y = prev_y + arm_length;
                if (checkOddInner(i, x, y)) {
                    ans += 'D';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }
            // D
            {
                ll x = prev_x;
                ll y = prev_y - arm_length;
                if (checkOddInner(i, x, y)) {
                    ans += 'U';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }
            // R
            {
                ll x = prev_x - arm_length;
                ll y = prev_y;
                if (checkOddInner(i, x, y)) {
                    ans += 'R';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }
            // L
            {
                ll x = prev_x + arm_length;
                ll y = prev_y;
                if (checkOddInner(i, x, y)) {
                    ans += 'L';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }


        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}

// ある点がn乗の範囲内に収まるか
int checkEvenInner(int n, ll x, ll y) {
    ll boundary = 1ll << (n);
    if (abs(x) + abs(y) <= boundary) {
        return true;
    }
    return false;
}

int maxEvenArmCount() {
    int ans = 0;
    for (P p : targets) {
        for (int i = 1; i < 40; i++) {
            if (checkEvenInner(i, p.first, p.second)) {
                ans = max(ans, i);
                break;
            }
        }
    }
    return ans;
}


void culcEven() {

    // ある点を含む最小の2のn乗
    // 奇数の時だけ考える

    int max_arm_count = maxEvenArmCount();
    cout << (max_arm_count + 1) << endl;

    cout << 1 << ' ';
    for (int i = 1; i <= max_arm_count; i++) {
        cout << (1ll << (i - 1)) << ' ';
    }
    cout << endl;


    for (P p : targets) {
        string ans = "";
        ll prev_x = p.first;
        ll prev_y = p.second;
        for (int i = (max_arm_count - 1); i >= 0; i--) {
            ll arm_length = 1ll << i;
            // U
            {
                ll x = prev_x;
                ll y = prev_y + arm_length;
                if (checkEvenInner(i, x, y)) {
                    ans += 'D';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }
            // D
            {
                ll x = prev_x;
                ll y = prev_y - arm_length;
                if (checkEvenInner(i, x, y)) {
                    ans += 'U';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }
            // L
            {
                ll x = prev_x - arm_length;
                ll y = prev_y;
                if (checkEvenInner(i, x, y)) {
                    ans += 'R';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }
            // R
            {
                ll x = prev_x + arm_length;
                ll y = prev_y;
                if (checkEvenInner(i, x, y)) {
                    ans += 'L';
                    prev_x = x;
                    prev_y = y;
                    continue;
                }
            }


        }
        [&] {
            // ここから最後の一本
            // U
            {
                ll x = prev_x;
                ll y = prev_y + 1;
                if (x == 0 && y == 0) {
                    ans += 'D';
                    return;
                }
            }
            // D
            {
                ll x = prev_x;
                ll y = prev_y - 1;
                if (x == 0 && y == 0) {
                    ans += 'U';
                    return;
                }
            }
            // L
            {
                ll x = prev_x - 1;
                ll y = prev_y;
                if (x == 0 && y == 0) {
                    ans += 'R';
                    return;
                }
            }
            // R
            {
                ll x = prev_x + 1;
                ll y = prev_y;
                if (x == 0 && y == 0) {
                    ans += 'L';
                    return;
                }
            }
        }();
        // ここまで最後の一本

        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}

int main() {

    int n;
    cin >> n;

    rep(i, n) {
        int x, y;
        cin >> x >> y;

        P p(x, y);
        targets.push_back(p);
    }

    if (!checkEnability()) {
        cout << -1 << endl;
        return 0;
    }

    if ((targets[0].first + targets[0].second) % 2 == 0) {
        culcEven();
    } else {
        culcOdd();
    }

}

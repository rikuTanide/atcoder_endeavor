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

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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


struct Work {
    int index, start, end;
};

struct Schedule {
    int work_index, count;
};

Schedule minw(Schedule s1, Schedule s2) {
    if (s1.count > s2.count) return s1;
    if (s1.count < s2.count) return s2;
    if (s1.work_index < s2.work_index) return s1;
    return s2;
}

int main() {
    int n;
    cin >> n;

    vector<Work> works(n);
    rep(i, n) works[i].index = i, cin >> works[i].start >> works[i].end;
    int MAX = 1000005;
//    int MAX = 12;
    vector<vector<Work>> work_end(MAX);
    for (Work &w : works) work_end[w.end].push_back(w);

    vector<Schedule> dp(MAX, {-1, 0});
    for (int i = MAX - 2; i >= 0; i--) {
        dp[i] = minw(dp[i], dp[i + 1]);

        for (Work &w : work_end[i]) {
            dp[w.start] = minw(dp[w.start], Schedule{w.index, dp[i].count + 1});
        }
    }

    cout << dp[0].count << endl;

    int i = 0;
    vector<int> ans;
    while (true) {
        Schedule s = dp[i];
        if (s.work_index == -1) break;
        ans.push_back(s.work_index + 1);
        int wi = s.work_index;
        i = works[wi].end;
    }
    rep(j, ans.size()) {
        cout << ans[j];
        if (j == ans.size() - 1) cout << endl;
        else cout << ' ';

    }

}

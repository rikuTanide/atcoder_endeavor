#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

typedef pair<int, int> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int cycle_first(int a, vector<ll> &dict) {
    int i = 0;
    set<int> used;
    int now = a;
    while (!contain(used, now)) {
        used.insert(now);
        now = dict[now];
        i++;
    }
    return now;
}

int get_first(int target, int a, vector<ll> &dict) {
    int i = 0;
    int now = a;
    while (now != target) {
        now = dict[now];
        i++;
    }
    return i;
}

int get_cycle_len(int target, vector<ll> &dict) {
    int i = 0;
    int now = dict[target];
    while (now != target) {
        now = dict[now];
        i++;
    }
    return i + 1;
}

int count_ans(int k, int a, vector<ll> &dict) {
    int ans = a;
    for (int j = 0; j < k; j++) {
        ans = dict[ans];
    }
    return ans + 1;
}

int main() {
    int n, a;
    ll k;
    cin >> n >> a >> k;

    a--;
    vector<ll> dict(n);
    rep(i, n) cin >> dict[i], dict[i]--;
    int first_position = cycle_first(a, dict);
    int first = get_first(first_position, a, dict);
    int cycle_len = get_cycle_len(first_position, dict);

    if (first >= k) {
        cout << count_ans(k, a, dict) << endl;
        ret();
    }

    k -= first;
    k %= cycle_len;

    cout << count_ans(k, first_position, dict) << endl;

}

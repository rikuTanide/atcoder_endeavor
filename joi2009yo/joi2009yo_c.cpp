#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int check(int l, int center, int r, vector<int> &seq, vector<int> &seq_type) {

    int ans = 0;


    if (seq[l] == 0) l--;
    if (seq[r] == 0) r++;
    if (seq_type[center] == seq_type[l]) {
        ans += seq[l];
        l--;
    }
    if (seq_type[center] == seq_type[r]) {
        ans += seq[r];
        r++;
    }

    while (true) {

        if (seq_type[l] != seq_type[r]) break;
        if (seq[l] + seq[r] < 4) break;
        ans += seq[l];
        ans += seq[r];
        l--;
        r++;
    }
    return ans;
}

ll solve(vector<int> &seq, vector<int> &seq_type) {
    int n = seq.size();
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int nt = seq_type[i];
        int nc = seq[i];

        int a = [&] {
            seq[i]--;
            seq[i - 1]++;
            if (seq[i - 1] < 4 && seq[i - 1] != 0) {
                seq[i]++;
                seq[i - 1]--;
                return 0;
            }
            int now = check(i - 2, i - 1, i, seq, seq_type) + seq[i - 1];
            seq[i]++;
            seq[i - 1]--;
            return now;
        }();

        int b = [&] {
            seq[i]--;
            seq[i + 1]++;
            if (seq[i + 1] < 4 && seq[i + 1] != 0) {
                seq[i]++;
                seq[i + 1]--;
                return 0;
            }
            int now = check(i, i + 1, i + 2, seq, seq_type) + seq[i + 1];
            seq[i]++;
            seq[i + 1]--;
            return now;
        }();


        int now = max(a, b);
        cmax(ans, now);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    v.insert(v.begin(), 4);
    v.push_back(4);

    vector<int> seq;
    vector<int> seq_type;


    seq.push_back(1);
    seq_type.push_back(4);
    for (int i = 1; i < v.size(); i++) {
        if (seq_type.back() == v[i]) {
            seq.back()++;
        } else {
            seq.push_back(1);
            seq_type.push_back(v[i]);
        }
    }

    assert(seq.size() == seq_type.size());

    int ans = n - solve(seq, seq_type);

    cout << ans << endl;
}
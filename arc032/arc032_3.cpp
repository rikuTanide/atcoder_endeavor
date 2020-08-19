#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Job {
    int id, start, end;
};

std::istream &operator>>(std::istream &in, Job &o) {
    in >> o.start >> o.end;
    return in;
}

struct Cell {
    int count;
    int last;
};
const int MAX = 20;

int main() {
    int n;
    cin >> n;
    vector<Job> v(n);
    for (Job &p:v) cin >> p;
    rep(i, n) v[i].id = i;

    vector<vector<Job>> t_jobs(MAX);

    for (Job job : v) t_jobs[job.end].push_back(job);

    vector<Cell> dp(MAX, Cell{-1, -1});

    auto set = [&](int i, int count, int last) {
        if (dp[i].count > count) return;
        if (dp[i].count < count) {
            dp[i].count = count;
            dp[i].last = last;
        }

        cmin(dp[i].last, last);

    };


    dp[MAX - 1] = {0, INT_MAX};
    for (int i = MAX - 2; i >= 0; i--) {
        set(i, dp[i + 1].count, dp[i + 1].last);
        for (Job job : t_jobs[i]) {
            set(job.start, dp[i].count + 1, job.id);
        }
    }

    cout << dp[0].count << endl;
    int now = 0;
    rep(i, dp[0].count) {
        cout << dp[now].last + 1 << ' ';
        Job job = v[dp[now].last];
        int end = job.end;
        now = end;
    }
    cout << endl;

}

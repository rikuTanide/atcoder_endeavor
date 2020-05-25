#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

bool check(int n, vector<int> &employees, vector<set<int>> &deny) {
    rep(i, n) {
        int c = employees[i];
        int r = employees[(i + n + 1) % n];
        int l = employees[(i + n - 1) % n];

        if (deny[c].find(r) != deny[c].end()) return false;
        if (deny[c].find(l) != deny[c].end()) return false;
    }
    return true;
}

#include <time.h>
#include <sys/time.h>

bool is_exit(timeval &start) {
    timeval now;
    gettimeofday(&now, NULL);

    ll s = ll(start.tv_sec) * 1000 * 1000 + start.tv_usec;
    ll n = ll(now.tv_sec) * 1000 * 1000 + now.tv_usec;

    ll diff = n - s;

    ll border = 1.9 * 1000 * 1000;

    return diff <= border;
}

int main() {
    srand((unsigned int) time(NULL));

    int n, m, k;
    cin >> n >> m >> k;

    vector<set<int>> deny(n);


    rep(i, m) {
        int a, b;
        cin >> a >> b;

        deny[a].insert(b);
        deny[b].insert(a);
    }

    double ok = 0, test = 0;

    timeval start;
    gettimeofday(&start, NULL);
    while (is_exit(start)) {
        test += 1;
        vector<int> employees(n);
        rep(i, n) employees[i] = i;

        rep(_, k) {
            int first = rand() % n;
            int second = rand() % (n - 1);
            if (first <= second) second++;
            swap(employees[first], employees[second]);
        }

        bool b = check(n, employees, deny);
        if (b) ok++;

    }

    printf("%.20f\n", ok / test);;

}

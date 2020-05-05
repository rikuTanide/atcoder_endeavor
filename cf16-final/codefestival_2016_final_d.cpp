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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    rep(i, n) cin >> numbers[i];

    sort(numbers.begin(), numbers.end());

    vector<vector<int>> ms(m);
    for (int i : numbers) ms[i % m].push_back(i);
    ll ans = 0;
    rep(i, m) {
        int j = m - i;
        if (i == 0 || i + i == m) {
            ans += ms[i].size() / 2;
            continue;
        }

        if (i < j) continue;

        vector<int> &v = ms[i], &u = ms[j];
        if (v.size() < u.size()) swap(v, u);

        map<int, int> mp;
        for (int k : v) mp[k]++;


        int pc = 0;
        for (auto e : mp) pc += e.second / 2;
        int noko = (v.size() - u.size()) / 2;

        int k = min(pc, noko);

        int now = k + u.size();
        ans += now;
    }

    cout << ans << endl;
}

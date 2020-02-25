#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


int main() {
    string s;
    cin >> s;

    queue<char> ss, ts;

    {
        string t;
        for (char c : s) if (c != 'x') t.push_back(c);
        string a = t.substr(0, t.size() / 2),
                b = t.substr((t.size() + 1) / 2);
        reverse(a.begin(), a.end());

        if (a != b) {
            cout << -1 << endl;
            ret();
        }

    }

    string t = s;
    reverse(t.begin(), t.end());
    for (char c : s) ss.push(c);
    for (char c : t) ts.push(c);

    int ans = 0;

    while (!ss.empty() || !ts.empty()) {
        if (ss.empty()) {
            assert(ts.front() == 'x');
            ans++;
            ts.pop();
            continue;
        }
        if (ts.empty()) {
            assert(ss.front() == 'x');
            ans++;
            ss.pop();
            continue;
        }
        if (ss.front() == ts.front()) {
            ss.pop();
            ts.pop();
            continue;
        }
        if (ss.front() == 'x') {
            ss.pop();
            ans++;
            continue;
        }
        if (ts.front() == 'x') {
            ts.pop();
            ans++;
            continue;
        }
        __throw_runtime_error("okasii");
    }

    cout << ans / 2 << endl;

}
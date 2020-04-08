#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

char max_char(string &s) {
    char c = *max_element(s.begin(), s.end());
    c++;
    return c;
}

int main() {
    int n;
    cin >> n;

    queue<string> q;
    q.push("a");
    while (!q.empty()) {
        string t = q.front();
        q.pop();
        if (t.size() == n) {
            cout << t << endl;
        } else {
            char c = max_char(t);
            for (char i = 'a'; i <= c; i++) {
                q.push(t + i);
            }
        }
    }
}

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


int main() {
    string s;
    cin >> s;

    vector<int> start_positions;
    rep(i, s.size() - 1) {
        if (s[i] == '2' && s[i + 1] == '5') {
            start_positions.push_back(i);
        }
    }

    vector<ll> sections;
    for (int i = 0; i < start_positions.size(); i++) {
        int index = start_positions[i];
        if (sections.empty()) sections.push_back(1);
        else if (start_positions[i - 1] + 2 == index) sections.back()++;
        else sections.push_back(1);
    }

    ll ans = 0;
    for (ll l : sections) ans += (l) * (l + 1) / 2;
    cout << ans << endl;


}

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

bool is_match(string &s, string &t, int i) {
    for (int j = 0; j < t.size(); j++) {
        if (s[i + j] == '?') continue;
        if (s[i + j] == t[j]) continue;
        return false;
    }
    return true;
}

string replace(string &s, string &t, int i) {
    string u;
    for (int j = 0; j < i; j++) {
        if (s[j] == '?') u.push_back('a');
        else u.push_back(s[j]);
    }
    for (int j = 0; j < t.size(); j++) {
        u.push_back(t[j]);
    }
    for (int j = i + t.size(); j < s.size(); j++) {
        if (s[j] == '?') u.push_back('a');
        else u.push_back(s[j]);
    }
    return u;
}

int main() {
    string _s, t;
    cin >> _s >> t;

    vector<string> candidate;

    for (int i = 0; i + t.size() <= _s.size(); i++) {
        bool b = is_match(_s, t, i);
        if (!b) continue;
        string s = replace(_s, t, i);
        candidate.push_back(s);
    }
    if (candidate.empty()) {
        cout << "UNRESTORABLE" << endl;
        ret();
    }
    sort(candidate.begin(), candidate.end());
    cout << candidate.front() << endl;
}
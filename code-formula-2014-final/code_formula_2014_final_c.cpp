#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
#include <cmath>

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

#include <iostream>
#include <vector>

using namespace std;


int main() {
    string s;
    getline(cin, s);

    bool in_at = false;
    string name = "";
    set<string> names;

    auto commit = [&] {
        if (!in_at) return;
        if (name == "") return;
        names.insert(name);
        name = "";
        in_at = false;
    };

    rep(i, s.size()) {
        char c = s[i];
        if (c == '@') {
            commit();
            in_at = true;
            name = "";
        } else if (c == ' ') {
            commit();
            in_at = false;
            name = "";
        } else if (in_at) {
            name += c;
        }
    }
    commit();
    for (string n : names) {
        cout << n << endl;
    }
}

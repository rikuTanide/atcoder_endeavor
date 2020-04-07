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

std::vector<std::string> split(std::string str, char del) {
    int first = 0;
    int last = str.find_first_of(del);

    std::vector<std::string> result;

    while (first < str.size()) {
        std::string subStr(str, first, last - first);

        result.push_back(subStr);

        first = last + 1;
        last = str.find_first_of(del, first);

        if (last == std::string::npos) {
            last = str.size();
        }
    }

    return result;
}

bool match(string &s, string &w) {
    if (w.size() != s.size()) return false;

    rep(i, w.size()) {
        if (s[i] == w[i]) continue;
        if (w[i] == '*') continue;
        return false;
    }
    return true;
}


bool str_equal(string &s, vector<string> &words) {
    for (string &w : words) {
        bool b = match(s, w);
        if (b) return true;
    }
    return false;
}

string kome_filter(int i) {
    string res = "";
    rep(j, i) {
        res += '*';
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);

    vector<string> ss = split(s, ' ');


    int n;
    cin >> n;
    vector<string> words(n);
    rep(i, n) cin >> words[i];

    for (string &t : ss) {
        if (str_equal(t, words)) {
            cout << kome_filter(t.size()) << ' ';
        } else {
            cout << t << ' ';
        }
    }
    cout << endl;
}

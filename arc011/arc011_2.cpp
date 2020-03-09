#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

map<char, int> convert = {
        {'b', 1},
        {'c', 1},

        {'d', 2},
        {'w', 2},

        {'t', 3},
        {'j', 3},

        {'f', 4},
        {'q', 4},

        {'l', 5},
        {'v', 5},

        {'s', 6},
        {'x', 6},

        {'p', 7},
        {'m', 7},

        {'h', 8},
        {'k', 8},

        {'n', 9},
        {'g', 9},

        {'z', 0},
        {'r', 0},
};

string tolower(string &str) {
    rep(i, str.size()) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string mapping(string &word) {
    string ans = "";
    for (char c : word) {
        if (convert.find(c) == convert.end()) continue;
        ans += (convert[c] + '0');
    }
    return ans;
}

void print_line(vector<string> &line) {
    if (line.size() == 0ll) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < line.size(); i++) {
        cout << line[i];
        if (i == line.size() - 1) cout << endl;
        else cout << ' ';
    }
}


int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    rep(i, n) cin >> words[i];
    rep(i, n) words[i] = tolower(words[i]);

    vector<string> ans;
    rep(i, n) {
        string t = mapping(words[i]);
        if (t == "") continue;
        ans.push_back(t);
    };

    print_line(ans);

}

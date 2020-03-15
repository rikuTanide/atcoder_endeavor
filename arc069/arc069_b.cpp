#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, int> P;
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

bool check(int n, const string &s, vector<char> &ans) {

    auto set = [&](int i, char a) {
        i = i % n;
        if (ans[i] == ' ') {
            ans[i] = a;
            return true;
        }
        if (ans[i] == a) {
            return true;
        }
        return false;
    };

    rep(i, n) {
        char c = s[i];
        char a = ans[i];
        char pa = ans[(n + i - 1) % n];
        if (a == 'S') {
            if (c == 'o') {
                if (pa == 'S') {
                    bool b = set(i + 1, 'S');
                    if (!b) return false;
                } else {
                    bool b = set(i + 1, 'W');
                    if (!b) return false;
                }
            } else {
                if (pa == 'S') {
                    bool b = set(i + 1, 'W');
                    if (!b) return false;
                } else {
                    bool b = set(i + 1, 'S');
                    if (!b) return false;
                }
            }
        } else {
            if (c == 'o') {
                if (pa == 'S') {
                    bool b = set(i + 1, 'W');
                    if (!b) return false;
                } else {
                    bool b = set(i + 1, 'S');
                    if (!b) return false;
                }
            } else {
                if (pa == 'S') {
                    bool b = set(i + 1, 'S');
                    if (!b) return false;
                } else {
                    bool b = set(i + 1, 'W');
                    if (!b) return false;
                }
            }
        }
    }
    return true;
}

int main() {

    int n;
    string s;
    cin >> n >> s;

    {
        vector<char> ans(n, ' ');
        // 羊---羊
        ans.back() = 'S';
        ans.front() = 'S';

        bool b = check(n, s, ans);
        if (b) {
            for (char c : ans) cout << c;
            cout << endl;
            ret();
        }
    }

    {
        vector<char> ans(n, ' ');
        // 羊---狼
        ans.back() = 'W';
        ans.front() = 'S';

        bool b = check(n, s, ans);
        if (b) {
            for (char c : ans) cout << c;
            cout << endl;
            ret();
        }
    }
    {
        vector<char> ans(n, ' ');
        // 狼---羊
        ans.back() = 'S';
        ans.front() = 'W';

        bool b = check(n, s, ans);
        if (b) {
            for (char c : ans) cout << c;
            cout << endl;
            ret();
        }
    }
    {
        vector<char> ans(n, ' ');
        // 狼---狼
        ans.back() = 'W';
        ans.front() = 'W';

        bool b = check(n, s, ans);
        if (b) {
            for (char c : ans) cout << c;
            cout << endl;
            ret();
        }
    }
    cout << -1 << endl;
}

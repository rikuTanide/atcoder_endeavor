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


int main() {
    int n, r;
    string s;
    cin >> n >> r;
    cin >> s;

    int last = -1;
    rep(i, n) if (s[i] == '.') last = i;
    if (last == -1) {
        cout << 0 << endl;
        ret();
    }

    // 銃を撃つ回数=貪欲
    int count = 0;
    for (char c : s) if (c == 'o') count++;
    int now = 0;
    int gun = 0;
    while (count < n) {
        char c = s[now];
        if (c == 'o') {
            now++;
            continue;
        }
        gun++;
        for (int i = now; i < min(n, now + r); i++) {
            char nc = s[i];
            if (nc == '.') {
                count++;
                s[i] = 'o';
            }
        }
    }

    // 一番最後に銃を撃つまでに移動しないといけない個数
    // = 最後の'.'-r
    int l = max(0, last - r);
    cout << gun + l + 1 << endl;

}

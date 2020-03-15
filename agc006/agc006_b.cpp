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


int main() {
    int n, x;
    cin >> n >> x;

    if (n == 2) {
        if (x == 2) {
            printf("Yes\n 1 2 3\n");
            ret();
        } else {
            cout << "No" << endl;
            ret();
        }
    }

    int ma = 2 * n - 1;
    if (x == 1 || x == ma) {
        cout << "No" << endl;
        ret();
    }

    vector<int> ans(ma, 0);
    ans[n - 1] = x;

    set<int> a;
    rep(i, ma) a.insert(i + 1);
    a.erase(x);

    if (x > n) {
        ans[n - 2] = x - 1;
        ans[n] = x + 1;
        ans[n + 1] = x - 2;

        a.erase(x - 1);
        a.erase(x + 1);
        a.erase(x - 2);

    } else {
        ans[n - 2] = x + 1;
        ans[n] = x - 1;
        ans[n + 1] = x + 2;

        a.erase(x + 1);
        a.erase(x - 1);
        a.erase(x + 2);
    }

    rep(i, ma) if (ans[i] == 0) {
            int k = *a.begin();
            ans[i] = k;
            a.erase(k);
        }

    cout << "Yes" << endl;
    for (int i : ans) cout << i << endl;

}

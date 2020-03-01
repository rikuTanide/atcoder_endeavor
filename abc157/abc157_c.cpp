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
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

bool check(vector<int> &bingo, int i, int j, int k) {
    return bingo[i] == -1 && bingo[j] == -1 && bingo[k] == -1;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> number(n, -1);

    rep(i, m) {
        int s, c;
        cin >> s >> c;
        s--;

        if (s == 0 && c == 0) {
            cout << -1 << endl;
            ret();
        }

        if (number[s] == -1) {
            number[s] = c;
        } else if (number[s] == c) {
            continue;
        } else {
            cout << -1 << endl;
            ret();
        }
    }

    if (number[0] == -1) number[0] = 1;
    for (int i = 1; i < n; i++) {
        if (number[i] == -1) number[i] = 0;
    }

    for (int num : number) cout << num;
    cout << endl;

}

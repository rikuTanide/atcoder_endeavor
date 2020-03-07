#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<double, double> P;
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
    int direction = 1;
    string s;
    int q;
    cin >> s >> q;

    list<char> l;
    for (char c : s) l.push_back(c);

    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) direction *= -1;
        else {
            int f;
            char c;
            cin >> f >> c;

            if (direction == -1) {
                if (f == 1) f = 2;
                else f = 1;
            }

            if (f == 1) {
                l.push_front(c);
            } else {
                l.push_back(c);
            }
        }
    }

    string ans = "";
    for (char c: l) {
        ans += c;
    }

    if (direction == -1) {
        reverse(ans.begin(), ans.end());
    }

    cout << ans << endl;


}

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

int main() {

    int n;
    cin >> n;
    vector<int> targets(n + 1, 0);
    rep(i, n) cin >> targets[i + 1];

    vector<int> boxes(n + 1, 0);

    for (int i = n; i >= 1; i--) {
        int sum = 0;
        // 本当はj = iではなくj = i + iで始めるべきだが、どうせboxes[i]は0なので
        for (int j = i; j <= n; j += i) {
            sum += boxes[j];
        }
        if (sum % 2 == targets[i]) continue;
        else boxes[i] = 1;
    }

    int c = 0;
    for (int i = 1; i <= n; i++) if (boxes[i] == 1) c++;
    cout << c << endl;
    for (int i = 1; i <= n; i++) if (boxes[i] == 1) cout << i << endl;

}

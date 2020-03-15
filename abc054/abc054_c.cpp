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

bool check(const vector<int> &arr, const vector<vector<bool>> &bridge) {
    for (int i = 1; i < arr.size(); i++) {
        int from = arr[i - 1];
        int to = arr[i];
        if (!bridge[from][to]) return false;
    }
    return true;
}

int main() {


    int n, m;
    cin >> n >> m;

    vector<vector<bool>> bridge(n, vector<bool>(n, false));
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        bridge[a][b] = true;
        bridge[b][a] = true;
    }

    vector<int> arr(n);
    rep(i, n)arr[i] = i;

    int ans = 0;
    do {
        if (arr[0] != 0) continue;
        bool b = check(arr, bridge);
        if (b) ans++;
    } while (std::next_permutation(arr.begin(), arr.end()));
    cout << ans << endl;
}

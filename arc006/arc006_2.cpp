#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
//typedef unsigned long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
//typedef pair<ll, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = (1ll << 31) - 1;
//const ll INF = 1e15;
//const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//typedef pair<int, int> P;
//typedef pair<double, double> P;
#define ret() return 0;

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;

vector<int> amida_simulator(vector<int> &horizontal, int width) {
    vector<int> currents(width);
    vector<int> current_indexes(width);
    rep(i, width) currents[i] = i;
    rep(i, width) current_indexes[i] = i;

    for (int h : horizontal) {
        int h1 = currents[h];
        int h2 = currents[h + 1];

        swap(current_indexes[h1], current_indexes[h2]);
        currents[h] = h2;
        currents[h + 1] = h1;

    }
    return current_indexes;
}

int main() {

    int n, l;
    cin >> n >> l;

    vector<int> horizontal;
    string t;
    getline(cin, t);
    rep(i, l) {
        string s;
        getline(cin, s);
        rep(j, 2 * n - 1) {
            char c = s[j];

            if (c == '-') {
                horizontal.push_back(j / 2);
            }
        }
    }

    reverse(horizontal.begin(), horizontal.end());


    vector<int> ans = amida_simulator(horizontal, n);

    string m;
    getline(cin, m);
    int index = distance(m.begin(), find(m.begin(), m.end(), 'o')) / 2;

    cout << ans[index] + 1 << endl;


}



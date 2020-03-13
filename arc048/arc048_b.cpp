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
    int n;
    cin >> n;


    vector<P> members(n);
    rep(i, n) cin >> members[i].first >> members[i].second;

    vector<int> rates(n);
    rep(i, n) rates[i] = members[i].first;
    sort(rates.begin(), rates.end());

    vector<vector<int>> methods(100001, vector<int>(4, 0));
    for (P p : members) {
        methods[p.first][p.second]++;
    }

    rep(i, n) {
        int x = members[i].first;
        int win = distance(rates.begin(), lower_bound(rates.begin(), rates.end(), x));
        int lose = distance(upper_bound(rates.begin(), rates.end(), x), rates.end());
        int draw = 0;

        if (members[i].second == 1) {
            draw = methods[x][1] - 1;
            win += methods[x][2];
            lose += methods[x][3];
        } else if (members[i].second == 2) {
            draw = methods[x][2] - 1;
            win += methods[x][3];
            lose += methods[x][1];
        } else {
            draw = methods[x][3] - 1;
            win += methods[x][1];
            lose += methods[x][2];
        }
        printf("%d %d %d\n", win, lose, draw);
    }
}

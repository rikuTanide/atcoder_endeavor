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
    int n, m;
    cin >> n >> m;

    for (int baby = 0; baby <= n; baby++) {
        int baby_leg = baby * 4;
        int adult_elder_leg = m - baby_leg;
        if (adult_elder_leg < 0) continue;
        int adult_elder_sum = n - baby;
        int elder = adult_elder_leg - 2 * adult_elder_sum;
        if (elder < 0) continue;
        int adult = adult_elder_sum - elder;
        if (adult < 0) continue;
        assert(baby >= 0);
        assert(adult >= 0);
        assert(elder >= 0);
        assert(baby + adult + elder == n);
        assert(baby * 4 + adult * 2 + elder * 3 == m);
        printf("%d %d %d\n", adult, elder, baby);
        ret();
    }
    cout << "-1 -1 -1" << endl;


}

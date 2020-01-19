#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

//typedef pair<char, ll> P;

ll to_odd(ll k) {
    while (k % 2 == 0) {
        k /= 2;
    }
    return k;
}

int main() {

    int n;
    cin >> n;

    vector<P> distances1(n, P(0, 0));
    for (int i = 0; i < n; i++) {
        if (i == 0) continue;
        printf("? %d %d\n", 1, i + 1);
        fflush(stdout);
        ll distance;
        cin >> distance;
        distances1[i].first = distance;
        distances1[i].second = i;
    }
    sort(distances1.rbegin(), distances1.rend());
    P far = distances1[0];


    vector<P> distances2(n, P(0, 0));
    for (int i = 0; i < n; i++) {
        if (i == far.second) continue;
        printf("? %lld %d\n", far.second + 1, i + 1);
        fflush(stdout);
        ll distance;
        cin >> distance;
        distances2[i].first = distance;
        distances2[i].second = i;
    }
    sort(distances2.rbegin(), distances2.rend());
    cout << distances2.front().first << endl;
}


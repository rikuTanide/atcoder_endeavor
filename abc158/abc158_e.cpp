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

bool contain(set<ll> &s, ll a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

int main() {

    ll n, p;
    string s;
    cin >> n >> p >> s;

    ll numMultiples = 0;
    vector<set<ll>> seenRemainders(n);

    for (ll i = 0; i < n; i++) {
        ll remainder = 0;
        ll prefixesFound = 0;
        for (ll j = i; j < n; j++) {
            ll next = s[j] - '0';
            remainder = (10 * remainder + next) % p;
            if (contain(seenRemainders[j], remainder)) {
                break;
            }
            seenRemainders[j].insert(remainder);
            if (remainder == 0) prefixesFound++;
        }
        numMultiples += prefixesFound * (prefixesFound + 1) / 2;
    }
    cout << numMultiples << endl;
}

#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
const ll INF = 10e17;
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

//const ll mod = 1e10;
//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int main() {
    int n;
    cin >> n;
    priority_queue<ll> slimes;
    rep(i, 1 << n) {
        ll s;
        cin >> s;
        slimes.push(s);
    }

    vector<ll> used;
    used.push_back(slimes.top());
    slimes.pop();

    rep(_, n) {
        vector<ll> new_slimes;
        for (ll s : used) {
            ll t = slimes.top();
            if (t >= s) {
                cout << "No" << endl;
                ret();
            }
            new_slimes.push_back(t);
            slimes.pop();
        }
        used.insert(used.end(), new_slimes.begin(), new_slimes.end());
    }
    cout << "Yes" << endl;
}
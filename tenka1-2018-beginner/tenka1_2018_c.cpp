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
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    sort(numbers.begin(), numbers.end());

    deque<ll> q;
    for (ll l : numbers) q.push_back(l);

    list<ll> l;
    l.push_back(q.front());
    q.pop_front();

    while (!q.empty()) {

        ll f = q.front();
        ll b = q.back();

        ll ff = abs(f - l.front());
        ll fb = abs(f - l.back());
        ll bf = abs(b - l.front());
        ll bb = abs(b - l.back());

        if (ff >= fb && ff >= bf && ff >= bb) {
            l.push_front(f);
            q.pop_front();
            continue;
        }
        if (fb >= ff && fb >= bf && fb >= bb) {
            l.push_back(f);
            q.pop_front();
            continue;
        }
        if (bf >= ff && bf >= fb && bf >= bb) {
            l.push_front(b);
            q.pop_back();
            continue;
        }
        if (bb >= ff && bb >= fb && bb >= bf) {
            l.push_back(b);
            q.pop_back();
            continue;
        }
        __throw_runtime_error("konai");
    }

    ll prev = l.front(), ans = 0;
    for (ll i : l) {
        ans += abs(i - prev);
        prev = i;
    }


    cout << ans << endl;
}
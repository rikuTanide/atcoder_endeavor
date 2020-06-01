#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

int bubble_sort(vector<ll> v) {
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < (n - 1); i++) {
        for (int j = n - 1; j > i; j--) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                ans++;
            }
        }
    }

    return ans;
}

vector<ll> bubble_sort2(vector<ll> v, int tts) {
    int n = v.size();
    for (int i = 0; i < (n - 1) && tts > 0; i++) {
        for (int j = n - 1; j > i; j--) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
                tts--;
                if (tts == 0) break;
            }
        }
    }
    return v;
}

int main() {
    int n;
    cin >> n;

    assert(n <= 3000);
    
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    for (ll &i : a) i--;
    for (ll &i : b) i--;


    map<ll, ll> m, ba;

    rep(i, n) m[a[i]] = i;
    rep(i, n) ba[i] = a[i];
    rep(i, n) a[i] = m[a[i]];
    rep(i, n) b[i] = m[b[i]];


    int tts = bubble_sort(b);
    if (tts % 2 == 1) {
        cout << -1 << endl;
        ret();
    }

    vector<ll> ans = bubble_sort2(b, tts / 2);

    rep(i, n) ans[i] = ba[ans[i]];

    for (ll &i : ans) i++;

    for (ll i : ans) cout << i << ' ';
    cout << endl;

}
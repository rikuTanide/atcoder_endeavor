#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, double> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


int main() {

//    ifstream infile("C:\\Users\\riku\\Downloads\\in1.txt");

    ll n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];
    ll sum = accumulate(numbers.begin(), numbers.end(), 0ll);
    vector<ll> cs(n, 0), rt(n, 0);
    ll one = n * (n + 1) / 2;
    if (sum % one != 0) {
        cout << "NO" << endl;
        ret();
    }
    ll count = sum / one;
    rep(i, n) {
        ll prev = (i + n - 1) % n;
        ll s = numbers[prev] - numbers[i];
        if ((s + count) % n != 0) {
            cout << "NO" << endl;
            ret();
        }
        if ((s + count) / n < 0) {
            cout << "NO" << endl;
            ret();
        }

        cs[i] = (s + count) / n;
    }

    rep(i, n) rt[0] += cs[i] * ((n - i) % n + 1);
    rep(i, n) if (i > 0) rt[i] = rt[i - 1] - cs[i] * n + count;

    rep(i, n) {
        if (rt[i] != numbers[i]) {
            cout << "NO" << endl;
            ret();
        }
    }
    cout << "YES" << endl;
}



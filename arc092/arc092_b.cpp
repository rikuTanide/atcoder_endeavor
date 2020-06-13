#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
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

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;


int check_bit(int a, vector<int> &bs, int j) {
    int t = 1 << j;

    int t1 = t - a;
    int t2 = 2 * t - a;
    int t3 = 3 * t - a;
    int t4 = 4 * t - a;


    int now = 0;
    for (int b :  bs) {
        if (t1 <= b && b < t2) now++;
        else if (t3 <= b && b < t4) now++;
    }

    return now;

}

vector<int> md(vector<int> &a, int j) {
    vector<int> ans(a.size());
    rep(i, a.size()) ans[i] = a[i] % (1 << j);
    return ans;
}

int main() {


    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> bits(30);

    rep(j, 30) {

        vector<int> al = md(a, j + 1);
        vector<int> bl = md(b, j + 1);

        rep(i, n) {
            int now = check_bit(al[i], bl, j);
            bits[j] += now;
        }
    }

    reverse(bits.begin(), bits.end());
    int ans = 0;
    for (int i : bits) {
        ans *= 2;
        int k = (i % 2);
        ans += k;
    }
    cout << ans << endl;

}
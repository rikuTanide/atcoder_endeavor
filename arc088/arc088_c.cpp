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

vector<int> get_counts(int n, string &s) {
    vector<int> counts(26, 0);
    for (char c : s) {
        int i = c - 'a';
        counts[i]++;
    }
    return counts;
}

vector<int> get_counts2(int n, vector<int> counts) {
    for (int &i:counts) i %= 2;
    return counts;
}

P get_oe(vector<int> counts) {
    int o = count(counts.begin(), counts.end(), 1);
    int e = count(counts.begin(), counts.end(), 0);
    return P(o, e);
}

vector<int> get_csh(vector<int> counts) {
    for (int &i:counts)i /= 2;
    return counts;
}

string create_hs(int n, string &s, vector<int> csh) {
    string t = "";

    rep(i, n) {
        char c = s[i];
        int j = c - 'a';
        if (csh[j] == 0) continue;
        t.push_back(c);
        csh[j]--;
    }

    return t;
}

vector<ll> create_indexes(string &next, int n, string &s) {

    vector<queue<int>> qs(26);
    rep(i, n) {
        char c = next[i];
        int j = c - 'a';
        qs[j].push(i);
    }

    vector<ll> v(n);
    rep(i, n) {
        char c = s[i];
        int j = c - 'a';
        int k = qs[j].front();
        v[i] = k;
        qs[j].pop();
    }
    return v;
}

// 1-indexedなので注意。
struct BIT {
private:
    vector<ll> bit;
    int N;

public:
    BIT(int size) {
        N = size;
        bit.resize(N + 1);
    }

    // 一点更新です
    void add(int a, ll w) {
        for (int x = a; x <= N; x += x & -x) bit[x] += w;
    }

    // 1~Nまでの和を求める。
    ll sum(int a) {
        int ret = 0;
        for (int x = a; x > 0; x -= x & -x) ret += bit[x];
        return ret;
    }
};

// ====================================================================
// https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
ll inversion(int n, vector<ll> v) {
    rep(i, n) v[i]++;
    ll ans = 0;
    BIT b(n);  // これまでの数字がどんな風になってるのかをメモる為のBIT
    for (int i = 0; i < n; i++) {
        ans += i - b.sum(v[i]); // BITの総和 - 自分より左側 ＝ 自分より右側
        b.add(v[i], 1); // 自分の位置に1を足す(ダジャレではないです)
    }
    return ans;
}


void odd(int n, string &s) {
    vector<int> cs = get_counts(n, s);
    vector<int> cs2 = get_counts2(n, cs);
    P oe = get_oe(cs2);
    if (oe.first != 1) {
        cout << -1 << endl;
        return;
    }

    auto it = find(cs2.begin(), cs2.end(), 1);
    int cci = distance(cs2.begin(), it);
    char cc = 'a' + cci;

    cs[cci]--;
    assert(cs[cci] % 2 == 0);
    vector<int> csh = get_csh(cs);
    string t = create_hs(n, s, csh);
    string u = t;
    reverse(u.begin(), u.end());

    string next = t + cc + u;

    cout << next << endl;

    vector<ll> is = create_indexes(next, n, s);

    ll ans = inversion(n, is);
    cout << ans << endl;
}

void even(int n, string &s) {
    vector<int> cs = get_counts(n, s);
    vector<int> cs2 = get_counts2(n, cs);
    P oe = get_oe(cs2);
    if (oe.first != 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> csh = get_csh(cs);
    string t = create_hs(n, s, csh);
    string u = t;
    reverse(u.begin(), u.end());

    string next = t + u;

    vector<ll> is = create_indexes(next, n, s);

    ll ans = inversion(n, is);
    cout << ans << endl;
}


int main() {
    string s;
    cin >> s;
//
//    ifstream is("/home/riku/Downloads/23.txt");
//
//    is >> s;

    int n = s.size();


    if (n % 2 == 1) odd(n, s);
    else even(n, s);
}
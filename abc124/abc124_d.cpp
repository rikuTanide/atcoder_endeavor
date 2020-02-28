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

struct V {
    char v;
    int seq;
};

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return 0;
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

};

int main() {

    int n, k;
    cin >> n >> k;

    vector<V> vs;
    string s;
    cin >> s;

    for (char c : s) {
        if (vs.empty()) vs.push_back({c, 1});
        else if (vs.back().v == c) vs.back().seq++;
        else vs.push_back({c, 1});
    }

    CumulativeSum cs(vs.size());
    rep(i, vs.size()) {
        cs.set(i, vs[i].seq);
    }
    cs.calculate();


    int ans = 0;
    for (int i = 0; i < vs.size(); i++) {
        int seq = vs[i].seq;
        char v = vs[i].v;

        if (v == '0') {
            int ma = min(i + k * 2 - 1, (int) vs.size() - 1);
            int now = cs.getSectionSum(i, ma);
//            printf("%d %d\n", i, ma - i);
            cmax(ans, now);
        } else {
            int ma = min(i + k * 2, (int) vs.size() - 1);
            int now = cs.getSectionSum(i, ma);
//            printf("%d %d\n", i, ma - i);
            cmax(ans, now);
        }
    }
    cout << ans << endl;
}
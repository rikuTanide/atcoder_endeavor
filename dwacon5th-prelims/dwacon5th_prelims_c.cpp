#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<ll> &o) {
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
        if (i == sums.size()) return sums.back();
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
    int n, q;
    string s;
    cin >> n >> s >> q;


    CumulativeSum dcs(n), mcs(n), ccs(n);
    rep(i, n) {
        char c = s[i];
        if (c == 'D') dcs.set(i, 1);
        else if (c == 'M') mcs.set(i, 1);
        else if (c == 'C') ccs.set(i, 1);
    }
    dcs.calculate();
    mcs.calculate();
    ccs.calculate();

    // あるCが自分の左に何個Mを持っているか
    CumulativeSum sum_cs(n);
    rep(i, n) {
        if (s[i] != 'C') continue;
        sum_cs.set(i, mcs.getSum(i - 1));
    }
    sum_cs.calculate();

    // DMC
    // Dから見てK以内にあるMの数と
    // Dから見てK以外にあるCの数

    rep(_, q) {
        int k;
        cin >> k;

        ll ans = 0;
        rep(i, n) {
            if (s[i] != 'D')continue;
            ll all = sum_cs.getSectionSum(i, min(i + k - 1, n));
            ll left_m = mcs.getSectionSum(0, i);
            ll inner_c = ccs.getSectionSum(i, min(i + k - 1, n));
            ll sub = left_m * inner_c;
            ll now = all - sub;
            ans += now;
        }
        cout << ans << endl;

/*
        rep(i, n) {
            if (s[i] != 'M') continue;
            ll l = dcs.getSectionSum(0, i - 1);
            ll r = ccs.getSectionSum(i + 1, n);

            ll now = l * r;
            all += now;
        }

        ll sub = 0;
        rep(i, n - k + 1) {
            if (s[i] != 'D') continue;
            ll m = mcs.getSectionSum(i, i + k);
            ll c = dcs.getSectionSum(i + k, n);

            ll now = m * c;
            sub += now;
        }
        ll ans = all - sub;
        */

    }

}
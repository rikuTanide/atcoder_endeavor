#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct FirstSplit {
    ll first_w, first_h;
    ll second_w, second_h;
};

struct SecondSplit {
    ll first_w, first_h;
    ll second_w, second_h;
    ll third_w, third_h;
};

class Left {
    PQ_ASK q;
    ll score = 0;
public:

    void set(ll n) {
        score += n;
        q.push(n);
    }

    void push(ll n) {
        score += n;
        q.push(n);
        ll m = q.top();
        score -= m;
        q.pop();
    }

    ll getScore() {
        return score;
    }
};

class CumulativeMax {
    vector<ll> numbers;
    vector<ll> maximum;
public:
    CumulativeMax(ll n) {
        numbers.resize(n);
        maximum.resize(n);
    }

    void set(ll i, ll n) {
        numbers[i] = n;
    }

    void calculate() {
        maximum[numbers.size() - 1] = numbers.back();
        for (ll i = numbers.size() - 2; i >= 0; i--) {
            maximum[i] = max(maximum[i + 1], numbers[i]);
        }
    }

    ll getMax(ll i) {
        return maximum[i];
    }

};

class Right {

    vector<ll> initial;
    multiset<ll> used;
    multiset<ll> ignore;
    queue<ll> all;

    ll score = 0;

public:
    Right(ll n) {
        initial.resize(n * 2);
    }

    void set(ll i, ll n) {
        initial[i] = n;
        all.push(n);
    }

    void calculate(ll n) {
        sort(initial.rbegin(), initial.rend());
        for (ll i = 0; i < n; i++) {
            ignore.insert(initial[i]);
        }
        for (int i = n; i < 2 * n; i++) {
            used.insert(initial[i]);
            score += initial[i];
        }
    }

    ll pop() {
        ll f = all.front();
        auto it = used.find(f);
        if (it != used.end()) {
            score -= f;
            auto ignore_it = ignore.begin();
            ll t = *ignore_it;
            ignore.erase(ignore_it);
            score += t;
            used.erase(it);
            used.insert(t);
        } else {
            auto ignore_it = ignore.find(f);
            ignore.erase(ignore_it);
        }
        all.pop();
        return f;
    }

    ll getScore() {
        return score;
    }

};


int main() {

    ll n;
    cin >> n;

    Left l;
    Right r(n);

    rep(i, n) {
        ll a;
        cin >> a;
        l.set(a);
    }
    rep(i, 2 * n) {
        ll a;
        cin >> a;
        r.set(i, a);
    }
    r.calculate(n);


    ll ans = l.getScore() - r.getScore();

    rep(i, n) {
        ll p = r.pop();
        l.push(p);
        ll now = l.getScore() - r.getScore();
        cmax(ans, now);
    }

    cout << ans << endl;


}


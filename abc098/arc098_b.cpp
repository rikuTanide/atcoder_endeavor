#include <bits/stdc++.h>
#include <cmath>

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

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

#include <iostream>
#include <vector>

using namespace std;


class TowPointerListener {

public:
    virtual bool check_begin(int i) = 0;

    virtual void begin(int i) = 0;

    virtual bool check_right(int right) = 0;

    virtual void push_right(int right) = 0;

    virtual void pop_left(int left) = 0;

    virtual void dead_end(int left, int right) = 0;
};

class TowPointer {

    int n;
    TowPointerListener &tpl;


    vector<P> get_ranges() {
        vector<bool> enable_items(n);
        rep(i, n) enable_items[i] = tpl.check_begin(i);

        auto start = [&](int i) {
            if (i == 0) {
                return enable_items[i] == true;
            }
            if (!enable_items[i - 1] && enable_items[i]) {
                return true;
            }
            return false;
        };

        auto end = [&](int i) {

            if (i == n - 1) {
                return enable_items[i] == true;
            }

            if (enable_items[i] && !enable_items[i + 1]) {
                return true;
            }

            return false;
        };

        vector<P> ans;
        P p;
        rep(i, n) {
            if (start(i)) {
                p = P(i, -1);
            }
            if (end(i)) {
                p.second = i;
                ans.push_back(p);
            }
        }
        return ans;
    }

    void _go(P range) {
        int right = -1;
        for (int left = range.first; left <= range.second; left++) {
            if (right < left) {
                right = left;
                tpl.begin(left);
            }
            while (right + 1 <= range.second && tpl.check_right(right + 1)) {
                right++;
                tpl.push_right(right);
            }
            tpl.dead_end(left, right);
            tpl.pop_left(left);
        }
    }

public:
    TowPointer(int n, TowPointerListener &tpl) : n(n), tpl(tpl) {}

    void go() {

        vector<P> ranges = get_ranges();

        for (P range: ranges) _go(range);

    }


};


class TowPointerListenerImpl : public TowPointerListener {

    vector<ll> &numbers;
    ll sum = 0;

public:
    TowPointerListenerImpl(vector<ll> &numbers) : numbers(numbers) {}

    bool check_begin(int i) {
        return true;
    }

    void begin(int i) {
        sum = numbers[i];
    }

    bool check_right(int right) {
        return (sum + numbers[right]) == (sum ^ numbers[right]);
    }

    void push_right(int right) {
        sum += numbers[right];
    }

    void pop_left(int left) {
        sum -= numbers[left];
    }

    ll ans = 0;

    void dead_end(int left, int right) {
        ll now = right - left + 1;
        ans += now;
    }
};

int main() {
    int n;
    cin >> n;

    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];


    TowPointerListenerImpl listener(numbers);
    TowPointer tp(n, listener);
    tp.go();
    cout << listener.ans << endl;

}

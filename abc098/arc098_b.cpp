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

void tow_pointer(int n,
                 function<bool(int left)> check_begin,
                 function<void(int left)> begin,
                 function<bool(int right)> check_right,
                 function<void(int right)> push_right,
                 function<void(int left)> pop_left,
                 function<void(int left, int right)> dead_end
) {

    auto go = [&](P range) {
        int right = -1;
        for (int left = range.first; left <= range.second; left++) {
            if (right < left) {
                right = left;
                begin(left);
            }
            while (right + 1 <= range.second && check_right(right + 1)) {
                right++;
                push_right(right);
            }
            dead_end(left, right);
            pop_left(left);
        }
    };


    auto get_ranges = [&] {
        vector<bool> enable_items(n);
        rep(i, n) enable_items[i] = check_begin(i);

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
    };


    vector<P> ranges = get_ranges();
    for (P range: ranges) go(range);
}


int main() {
    int n;
    cin >> n;
    set<ll> sweets;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    ll sum = 0;
    auto check_begin = [&](int i) {
        return true;
    };

    auto begin = [&](int i) {
        sum = numbers[i];
    };

    auto check_right = [&](int right) {
        return (sum + numbers[right]) == (sum ^ numbers[right]);
    };

    auto push_right = [&](int right) {
        sum += numbers[right];

    };
    auto pop_left = [&](int left) {
        sum -= numbers[left];

    };

    ll ans = 0;

    auto dead_end = [&](int left, int right) {
        ll now = right - left + 1;
        ans += now;
    };


    tow_pointer(
            n,
            check_begin,
            begin,
            check_right,
            push_right,
            pop_left,
            dead_end
    );
    cout << ans << endl;

}

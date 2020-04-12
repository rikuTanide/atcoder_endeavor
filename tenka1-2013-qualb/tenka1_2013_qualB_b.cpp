#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

int main() {
    ll q, l;
    cin >> q >> l;

    struct Element {
        ll t, c;
    };

    stack<Element> stack;

    ll size = 0;
    rep(i, q) {
        string type;
        cin >> type;
        if (type == "Push") {
            ll e, c;
            cin >> c >> e;

            size += c;
            if (size > l) {
                cout << "FULL" << endl;
                ret();
            }

            if (!stack.empty() && stack.top().t == e) {
                stack.top().c += c;
            } else {
                stack.push({e, c});
            }

        } else if (type == "Top") {
            if (stack.empty()) {
                cout << "EMPTY" << endl;
                ret();
            }
            cout << stack.top().t << endl;
        } else if (type == "Size") {
            cout << size << endl;
        } else if (type == "Pop") {
            ll c;
            cin >> c;
            size -= c;
            if (size < 0) {
                cout << "EMPTY" << endl;
                ret();
            }
            while (c > 0) {
                if (stack.top().c > c) {
                    stack.top().c -= c;
                    c = 0;
                } else {
                    c -= stack.top().c;
                    stack.pop();
                }
            }
        }
    }

    cout << "SAFE" << endl;
}

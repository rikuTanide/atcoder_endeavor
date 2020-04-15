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


const int mod = 1000000007;

int main() {
    string a, b;
    cin >> a >> b;

    vector<int> ha(26), hb(26);
    for (char c : a) ha[c - 'a']++;
    for (char c : b) hb[c - 'a']++;

    if (ha != hb) {
        cout << "NO" << endl;
        ret();
    }

//    rep(i, 26) {
//        if (ha[i] == hb[i]) continue;
//        cout << "NO" << endl;
//        ret();
//    }

    string s = "", t = "";
    rep(i, a.size()) {
        if (a[i] == b[i]) continue;
        s.push_back(a[i]);
        t.push_back(b[i]);
    }

    if (s.size() >= 7) {
        cout << "NO" << endl;
//        ret();
    }

    vector<P> pairs;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            pairs.emplace_back(i, j);
        }
    }
    assert(pairs.size() <= 120);

    bool has_margin = (*max_element(ha.begin(), ha.end())) >= 2;

    {
        // 3回の交換
        for (P p : pairs) {
            for (P q : pairs) {
                for (P r : pairs) {
                    string v = s, u = t;
                    swap(v[p.first], v[p.second]);
                    swap(v[q.first], v[q.second]);
                    swap(v[r.first], v[r.second]);
                    if (v == u) {
                        cout << "YES" << endl;
                        ret();
                    }
                }
            }
        }
    }

    if (has_margin) {
        // 2回の交換
        for (P p : pairs) {
            for (P q : pairs) {
                string v = s, u = t;
                swap(v[p.first], v[p.second]);
                swap(v[q.first], v[q.second]);
                if (v == u) {
                    cout << "YES" << endl;
                    ret();
                }
            }
        }
    }

    {
        // 1回の交換
        for (P p : pairs) {
            string v = s, u = t;
            swap(v[p.first], v[p.second]);
            if (v == u) {
                cout << "YES" << endl;
                ret();
            }
        }
    }


    if (has_margin && a == b) {
        // 0回の交換

        cout << "YES" << endl;
        ret();
    }

    cout << "NO" << endl;
}


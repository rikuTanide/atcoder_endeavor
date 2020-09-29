#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

class TrieTree {

    class Node {
        vector<int> alphabet;
        int end_count = 0;
    public:
        Node() : alphabet(26, -1) {}

        void add_end() {
            end_count++;
        }

        int find(char c) {
            return this->alphabet[c - 'a'];
        }

        void make(char c, int i) {
            assert(this->alphabet[c - 'a'] == -1);
            this->alphabet[c - 'a'] = i;
        }

        bool has_end() {
            return end_count > 0;
        }

    };

    vector<Node> v;

public:
    TrieTree() {
        Node node;
        v.push_back(node);
    }

    void insert(string s) {
        int now = 0;
        for (char c : s) {
            int i = find(now, c);
            if (i == -1) {
                i = make(now, c);
            }
            now = i;
        }
        add_end(now);
    }

    int find(int i, char c) {
        return v[i].find(c);
    }

    int make(int i, char c) {
        v.push_back(Node());
        int j = v.size() - 1;
        v[i].make(c, j);
        return j;
    }

    void add_end(int i) {
        v[i].add_end();
    }

    bool has_end(int i) {
        return v[i].has_end();
    }
};

int main() {


    int n;
    cin >> n;
    vector<string> v(n);
    rep(i, n) cin >> v[i];

    for (string &s:v) reverse(s.begin(), s.end());

    TrieTree trieTree;
    for (string &s:v) trieTree.insert(s);

    ll ans = 0;

    for (string &s: v) {

        vector<int> used(26, 0);
        for (char c : s) used[c - 'a']++;
        int now = 0;

        for (char c : s) {
            rep(i, 26) {
                if (used[i] == 0) continue;
                int next = trieTree.find(now, 'a' + i);
                if (next != -1 && trieTree.has_end(next)) {
                    ans++;
                }
            }
            now = trieTree.find(now, c);
            used[c - 'a']--;
        }

    }
    ans -= n;
    cout << ans << endl;

}

#include <bits/stdc++.h>


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<string> &o) {
    string a;
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

typedef pair<ll, ll> P;

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Word {
    string num, target;
};

std::istream &operator>>(std::istream &in, Word &o) {
    cin >> o.num >> o.target;
    return in;
}

bool rec(map<char, string> &dict, vector<Word> &words, int wi, int ci, int ni) {
    if (wi == words.size()) return true;

    Word w = words[wi];


    if (ni == w.num.size()) {
        bool b = ci == w.target.size();
        if (!b) return false;
        return rec(dict, words, wi + 1, 0, 0);
    }

    char num = w.num[ni];
    if (dict.find(num) != dict.end()) {
        string match = dict[num];
        if (w.target.substr(ci, match.size()) == dict[num]) {
            return rec(dict, words, wi, ci + match.size(), ni + 1);
        } else {
            return false;
        }
    }

    rep(i, 3) {
        if (ci + i >= w.target.size()) {
            continue;
        }
        string next = w.target.substr(ci, i + 1);
        dict[num] = next;
        bool b = rec(dict, words, wi, ci + next.size(), ni + 1);
        if (b) return true;
        dict.erase(num);
    }
    return false;
}

int main() {
    int k, n;
    cin >> k >> n;

    vector<Word> words(n);
    rep(i, n) cin >> words[i];

    map<char, string> dict;

    bool b = rec(dict, words, 0, 0, 0);
    assert(b);

    for (char c = '1'; c <= '0' + k; c++) {
        cout << dict[c] << endl;
    }

}

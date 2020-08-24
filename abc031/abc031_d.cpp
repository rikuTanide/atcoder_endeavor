#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


struct Pair {
    string number;
    string word;
};


struct Index {
    int pair_id, number_index, word_index;
};

struct Pairs {
    vector<Pair> pairs;

    Pairs(int n) : pairs(n) {}

    char getChar(Index index) {
        return pairs[index.pair_id].number[index.number_index];
    }

    bool check(Index index, string term) {
        string cut = subStr(index, term.size());
        if (cut == "") return false;
        return cut == term;
    }

    string subStr(Index index, int term_len) {
        string &word = pairs[index.pair_id].word;
        int word_len = word.size();
        if (word_len < index.word_index + term_len) return "";
        string cut = word.substr(index.word_index, term_len);
        return cut;
    }

    Index next(Index index, int l) {
        Index nx = {
                index.pair_id,
                index.number_index + 1,
                index.word_index + l,
        };
        string word = pairs[index.pair_id].word;
        string number = pairs[index.pair_id].number;

        assert(nx.word_index <= word.size());
        assert(nx.number_index <= number.size());

        if (nx.word_index == word.size() || nx.number_index == number.size()) {
            if (nx.word_index == word.size() && nx.number_index == number.size()) {
                return Index{
                        index.pair_id + 1,
                        0,
                        0,
                };
            }
            return Index{
                    -1,
                    0,
                    0,
            };
        }

        return nx;
    }


};

struct Rule {
    map<char, string> rules;

    bool hasRule(char c) {
        return rules.find(c) != rules.end();
    }

    string getRule(char c) {
        assert(rules.find(c) != rules.end());
        return rules[c];
    }

    void add(char c, string term) {
        assert (rules.find(c) == rules.end());
        rules[c] = term;
    }

    void remove(char c, string term) {
        assert(rules[c] == term);
        rules.erase(rules.find(c));
    }

};

bool recursive(Pairs &pairs, Rule &rule, Index index) {
    if (index.pair_id == pairs.pairs.size()) return true;
    if (index.pair_id == -1) return false;

    char c = pairs.getChar(index);
    if (rule.hasRule(c)) {
        if (!pairs.check(index, rule.getRule(c))) return false;
        Index nextIndex = pairs.next(index, rule.getRule(c).size());
        return recursive(pairs, rule, nextIndex);
    }

    for (int l = 1; l <= 3; l++) {
        string next = pairs.subStr(index, l);
        if (next == "") continue;
        rule.add(c, next);
        Index nextIndex = pairs.next(index, l);
        bool ok = recursive(pairs, rule, nextIndex);
        if (ok) return true;
        rule.remove(c, next);
    }

    return false;

}

int main() {
    int k, n;
    cin >> k >> n;

    Pairs pairs(n);
    for (Pair &pair: pairs.pairs) cin >> pair.number >> pair.word;
    Rule rule;
    bool ok = recursive(pairs, rule, {0, 0, 0});
    assert(ok);

    for (int i = 1; i <= k; i++) {
        char c = '0' + i;
        cout << rule.getRule(c) << endl;
    }

}

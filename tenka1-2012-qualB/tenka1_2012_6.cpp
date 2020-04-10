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

bool is_only_under_bar(string &s) {
    for (char c : s) {
        if (c != '_') return false;
    }
    return true;
}


int get_begin_under_bar(string &s) {
    rep(i, s.size()) {
        if (s[i] != '_') return i;
    }
    __throw_runtime_error("konai hazu");
}

int get_last_under_bar(string s) {
    reverse(s.begin(), s.end());
    return get_begin_under_bar(s);
}

char is_upper(char c) {
    return ('A' <= c && c <= 'Z');
};

vector<string> get_terms(string &s) {
    vector<int> dp(s.size(), -1);


    auto is_front = [&](int i) {
        if (i == 0) return true;
        if (s[i - 1] == '_') return true;
        if (is_upper(s[i])) return true;
        return false;
    };

    auto is_alphabet = [&](int i) {
        char c = s[i];
        if ('a' <= c && c <= 'z') return true;
        if ('A' <= c && c <= 'Z') return true;
        return false;
    };

    auto is_in_term = [&](int i) {
        return dp[i] >= 0;
    };

    auto is_number = [&](int i) {
        char c = s[i];
        if ('0' <= c && c <= '9') return true;
        return false;
    };

    rep(i, s.size()) {
        if (is_front(i)) {
            if (is_alphabet(i)) {
                dp[i] = 0;
            }
        } else {
            // 大文字は来ない
            // 1文字目も来ない
            if (is_alphabet(i) && is_in_term(i - 1)) {
                dp[i] = dp[i - 1] + 1;
            } else if (is_number(i) && is_in_term(i - 1)) {
                dp[i] = dp[i - 1] + 1;
            }
        }
    }

    auto to_lower = [&](char c) {
        if (!is_upper(c)) {
            return c;
        }
        int d = c - 'A';
        char ans = 'a' + d;
        return ans;
    };

    vector<string> ans;
    rep(i, s.size()) {
        if (dp[i] == 0) {
            string t = "";
            char c = to_lower(s[i]);
            t += c;
            ans.push_back(t);
        } else if (dp[i] > 0) {
            string t = ans.back();
            t += s[i];
            ans.back() = t;
        }
    }
    return ans;
}

string repeat_(int a) {
    string s = "";
    rep(i, a) {
        s += '_';
    }
    return s;
}

string create_snake_case(vector<string> &terms, int fa, int la) {
    string s = repeat_(fa);
    rep(i, terms.size()) {
        s += terms[i];
        if (i < terms.size() - 1) {
            s += '_';
        }
    }
    s += repeat_(la);
    return s;
}

string create_camel_case(vector<string> &terms, int fa, int la) {
    auto to_upper = [&](char c) {
        if (is_upper(c)) {
            return c;
        }
        int d = c - 'a';
        char ans = 'A' + d;
        return ans;
    };
    string s = repeat_(fa);
    rep(i, terms.size()) {
        string t = terms[i];
        if (i > 0) t[0] = to_upper(t[0]);
        s += t;
    }
    s += repeat_(la);
    return s;
}

int main() {
    string s;
    cin >> s;
    vector<bool> in_term(s.size());
    if (is_only_under_bar(s)) {
        cout << s << endl;
        ret();
    }

    int fa = get_begin_under_bar(s);
    int la = get_last_under_bar(s);

    vector<string> terms = get_terms(s);

    string cc = create_camel_case(terms, fa, la);
    string sc = create_snake_case(terms, fa, la);

    if (s == cc) {
        cout << sc << endl;
    } else if (s == sc) {
        cout << cc << endl;
    } else {
        cout << s << endl;
    }

}

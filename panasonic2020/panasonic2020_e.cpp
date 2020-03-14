#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, int> P;
const ll INF = 1e15;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
//#define ret() return 0;

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

vector<int> makeTable(const string &s) {
    int n = s.size();
    vector<int> ret(n + 1);
    ret[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) j = ret[j];
        ret[i + 1] = ++j;
    }
    return ret;
}

// str の中に word とマッチする場所のリストを返す
// ret のそれぞれの要素 el は, 「str[el] からの文字列が word と一致する」ことを示す
vector<int> kmp(const string &str, const string &word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m + i < n) {
        if (word[i] == str[m + i] || word[i] == '?' || str[m + i] == '?') {
            if (++i == (int) (word.size())) {
                ret.push_back(m);
                m = m + i - table[i];
                i = table[i];
            }
        } else {
            m = m + i - table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}

vector<int> kmp2(const string &str, int j, const string &word) {
    vector<int> table = makeTable(word), ret;
    int m = 0, i = 0, n = str.size();
    while (m + i < n) {
        if (word[i] == str[m + i] || word[i] == '?' || str[m + i] == '?') {
            if (++i == (int) (word.size())) {
                ret.push_back(m);
                m = m + i - table[i];
                i = table[i];
            }
        } else {
            m = m + i - table[i];
            if (i > 0) i = table[i];
        }
    }
    return ret;
}


int main() {
    string a, b, c;
    cin >> a >> b >> c;

    string q = "";
    rep(i, b.size()) q += '?';

    string qqaqq = q + q + a + q + q;


    vector<int> match_ab = kmp(qqaqq, b);

    for (int i : match_ab) {
        kmp2(qqaqq, i, c);
    }


}
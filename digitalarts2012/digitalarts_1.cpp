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

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

bool is_match(string &str, vector<string> &masks) {
    for (string &mask : masks) {
        bool match = [&] {
            if (mask.size() != str.size()) return false;
            rep(i, mask.size()) {
                if (mask[i] == '*' || mask[i] == str[i]) continue;
                return false;
            }
            return true;
        }();
        if (match) return true;
    }
    return false;
}

string to_mask(string &s) {
    string ans;
    rep(i, s.size()) ans.push_back('*');
    return ans;
}

int main() {
    string s;
    getline(cin, s);

    vector<string> strs = split(s, ' ');

    int n;
    cin >> n;
    vector<string> masks(n);
    rep(i, n) cin >> masks[i];

    rep (i, strs.size()) {
        string &str = strs[i];
        if (is_match(str, masks)) {
            cout << to_mask(str);
        } else {
            cout << str;
        }
        if (i == strs.size() - 1) cout << endl;
        else cout << ' ';
    }


}

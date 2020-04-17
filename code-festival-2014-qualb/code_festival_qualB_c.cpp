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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<int> s1_count(26), s2_count(26), s3_count(26);
    rep(i, s1.size()) s1_count[s1[i] - 'A']++;
    rep(i, s2.size()) s2_count[s2[i] - 'A']++;
    rep(i, s3.size()) s3_count[s3[i] - 'A']++;

    rep(i, s1.size()) if (s1_count[i] + s2_count[i] < s3_count[i]) {
            cout << "NO" << endl;
            ret();
        }

    int s1_used = 0, s2_used = 0;

    rep(i, s1.size()) {
        if (s3_count[i] > s2_count[i]) {
            int nokori = s3_count[i] - s2_count[i];
            s1_used += nokori;
        }
    }

    rep(i, s2.size()) {
        if (s3_count[i] > s1_count[i]) {
            int nokori = s3_count[i] - s1_count[i];
            s2_used += nokori;
        }
    }


    if (s1_used > s1.size() / 2) {
        cout << "NO" << endl;
        ret();
    }
    if (s2_used > s2.size() / 2) {
        cout << "NO" << endl;
        ret();
    }

    int s1_max = 0, s2_max = 0;
    rep(i, s1.size()) {
        s1_max += min(s1_count[i], s3_count[i]);
    }

    rep(i, s2.size()) {
        s2_max += min(s2_count[i], s3_count[i]);
    }

    if (s1_max < (s1.size() / 2)) {
        cout << "NO" << endl;
        ret();
    }

    if (s2_max < (s2.size() / 2)) {
        cout << "NO" << endl;
        ret();
    }
    
    cout << "YES" << endl;
}


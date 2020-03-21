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


void print_v(vector<int> &v) {
    for (int i : v) cout << i;
    cout << ' ';
}

int check(vector<int> v) {

    while (v.size() != 1) {
        vector<int> next;
        for (int i = 1; i < v.size(); i++) {
            int a = abs(v[i - 1] - v[i]);
            next.push_back(a);
        }
        v = next;
    }
    return v.front();
}

int check2(vector<int> v) {
    if (v.size() % 2 == 1) {
        vector<int> a(v.size() - 1), b(v.size() - 1);
        for (int i = 0; i < v.size() - 1; i++) {
            a[i] = v[i];
        }
        for (int i = 0; i < v.size() - 1; i++) {
            b[i] = v[i + 1];
        }
        int aa = check2(a);
        int ba = check2(b);
        return abs(aa - ba);
    }
    while (v.size() != 1) {
        if (v.size() % 2 == 1) return check2(v);
        vector<int> next;
        for (int i = 0; i < v.size(); i += 2) {
            int a = abs(v[i] - v[i + 1]);
            next.push_back(a);
        }
        v = next;
    }
    return v.front();
}


bool is_end(vector<int> &v) {
    for (int i : v) if (i != 2) return false;
    return true;
}


void digit(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 3) {
            v[i] = 1;
            v[i + 1]++;
        }
    }
}


int main() {

    int n;
    cin >> n;
    vector<int> digits(n);
    rep(i, n) {
        char c;
        cin >> c;
        int a = c - '0';
        digits[i] = a;
    }
    vector<int> digits2;
    rep(i, n - 1) {
        digits2.push_back(abs(digits[i] - digits[i + 1]));
    }


    cout << check2(digits2) << endl;

}




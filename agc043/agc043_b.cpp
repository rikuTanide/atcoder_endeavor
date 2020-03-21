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


vector<int> sub(vector<int> &v) {
    vector<int> v2(v.size() - 1);
    rep(i, v.size() - 1) {
        v2[i] = abs(v[i] - v[i + 1]);
    }
    return v2;
}

int check2(vector<int> v) {
    while (v.size() != 1) {
        if (v.size() % 2 == 0) {
            vector<int> next;
            for (int i = 0; i < v.size(); i += 2) {
                int a = abs(v[i] - v[i + 1]);
                next.push_back(a);
            }
            v = next;
        } else {
            v = sub(v);
        }
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

    vector<int> digits2 = sub(digits);
    cout << check2(digits2) << endl;

}




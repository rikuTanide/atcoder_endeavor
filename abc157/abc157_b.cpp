#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e15;
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

bool check(vector<int> &bingo, int i, int j, int k) {
    return bingo[i] == -1 && bingo[j] == -1 && bingo[k] == -1;
}

int main() {

    vector<int> bingo(9);
    rep(i, 9) cin >> bingo[i];

    int n;
    cin >> n;

    rep(f, n) {
        int a;
        cin >> a;

        rep(i, 9) if (bingo[i] == a) bingo[i] = -1;
    }

    bool b = false;
    b |= check(bingo, 0, 1, 2);
    b |= check(bingo, 3, 4, 5);
    b |= check(bingo, 6, 7, 8);
    b |= check(bingo, 0, 3, 6);
    b |= check(bingo, 1, 4, 7);
    b |= check(bingo, 2, 5, 8);
    b |= check(bingo, 0, 4, 8);
    b |= check(bingo, 2, 4, 6);

    if (b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}

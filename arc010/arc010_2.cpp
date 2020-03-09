#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
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

template<typename ... Args>
std::string format(const std::string &fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
    return std::string(&buf[0], &buf[0] + len);
}

int main() {
    vector<int> md = {
            0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    map<string, int> days;

    int k = 0;
    for (int i = 1; i <= 12; i++) {
        for (int d = 1; d <= md[i]; d++) {
            string s = format("%d/%d", i, d);
            days[s] = k;
            k++;
        }
    }

    vector<int> year(366, 0);
    for (int i = 0; i < 366; i++) {
        if (i % 7 == 0) year[i]++;
        if (i % 7 == 6) year[i]++;
    }

    int n;
    cin >> n;
    rep(i, n) {
        string day;
        cin >> day;

        auto it = days.find(day);
        assert(it != days.end());
        int d = (*it).second;
        year[d]++;

    }
    
    for (int i = 0; i < 365; i++) {
        if (year[i] >= 2) {
            year[i + 1] += (year[i] - 1);
            year[i] = 1;
        }
    }

    vector<int> dp(366, 0);
    rep(i, 366) {
        if (year[i] > 0) dp[i] = 1;
    }

    for (int i = 1; i <= 365; i++) {
        if (year[i] >= 1) {
            dp[i] += dp[i - 1];
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;

}

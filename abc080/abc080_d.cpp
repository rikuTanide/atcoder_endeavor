#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

struct Program {
    int start, end;
    bool enable;
};

class CumulativeSum {
    vector<ll> numbers;
    vector<ll> sums;

public:
    CumulativeSum(int n) {
        numbers.resize(n);
        sums.resize(n);
    }

    void set(int i, ll value) {
        numbers[i] = value;
    }

    ll getSum(int i) {
        if (i == -1) return 0;
        if (i == sums.size()) return 0;
        return sums[i];
    }

    ll getSectionSum(int start, int end) {
        return getSum(end) - getSum(start - 1);
    }

    void calculate() {
        for (int i = 0; i < numbers.size(); i++) {
            sums[i] = getSum(i - 1) + numbers[i];
        }
    }

    int get_max() {
        return *max_element(sums.begin(), sums.end());
    }


};

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<Program>> programs(c);
    rep(i, n) {
        int s, t, ci;
        cin >> s >> t >> ci;
        ci--;
        Program p = {s, t, true};
        programs[ci].push_back(p);
    }

    rep(i, c) {
        sort(programs[i].begin(), programs[i].end(), [](Program &p, Program &q) {
            return p.start < q.start;
        });
    }

    rep(i, c) {
        for (int j = 1; j < programs[i].size(); j++) {
            if (programs[i][j - 1].end == programs[i][j].start) {
                programs[i][j].start = programs[i][j - 1].start;
                programs[i][j - 1].enable = false;
            }
        }
    }

    vector<int> times(200000, 0);
    rep(i, c) {
        for (Program &p : programs[i]) {
            if (!p.enable) continue;
            times[p.start - 1]++;
            times[p.end]--;
        }
    }

    CumulativeSum cs(200000);
    rep(i, 200000) cs.set(i, times[i]);
    cs.calculate();

    int ma = cs.get_max();
    cout << ma << endl;
}


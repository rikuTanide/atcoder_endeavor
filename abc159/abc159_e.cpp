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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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

vector<vector<vector<int>>> get_splits(int h) {
    h--;
    vector<vector<vector<int>>> res;
    for (int i = 0; i < (1 << h); i++) {
        res.push_back({{0}});
        rep(j, h) {
            if ((i >> j) & 1) {
                res.back().push_back({j + 1});
            } else {
                res.back().back().push_back(j + 1);
            }
        }
    }
    return res;
}

vector<vector<vector<int>>> filter_k(vector<vector<vector<int>>> &splits, int k, vector<vector<char>> &grid, int w) {

    auto check_line = [&](vector<int> &line) {

        rep(x, w) {
            int count = 0;
            for (int y : line) {
                if (grid[y][x] == '1') count++;
            }
            if (count > k) return false;
        }

        return true;
    };

    auto check = [&](vector<vector<int>> &v) {
        for (auto l : v) {
            if (!check_line(l)) {
                return false;
            }
        }
        return true;
    };

    vector<vector<vector<int>>> res;

    for (auto v : splits) {
        if (!check(v)) {
            continue;
        }
        res.push_back(v);
    }
    return res;
}

int get_count(vector<vector<int>> &split, vector<vector<char>> &grid, int w, int k) {
    vector<int> count(split.size(), 0);
    int ans = 0;

    auto get_next_count = [&](int x) {
        vector<int> next_count(split.size(), 0);
        rep(i, split.size()) {
            vector<int> cell = split[i];
            for (int y : cell) {
                if (grid[y][x] == '1') next_count[i]++;
            }
        }
        return next_count;
    };

    auto can = [&](vector<int> &next_count) {
        rep(i, split.size()) {
            if (next_count[i] + count[i] > k) return false;
        }
        return true;
    };

    rep(x, w) {
        vector<int> next_count = get_next_count(x);
        bool b = can(next_count);
        if (b) {
            rep(i, split.size()) {
                count[i] += next_count[i];
            }
        } else {
            ans++;
            count = next_count;
        }
    }
    return ans;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<char>> grid(h, vector<char>(w));
    rep(y, h) rep(x, w) cin >> grid[y][x];

    auto sp = get_splits(h);

    sp = filter_k(sp, k, grid, w);

    vector<int> candidate;
    for (auto s : sp) {
        int count = get_count(s, grid, w, k);
        count += (s.size() - 1);
        candidate.push_back(count);
    }

    cout << *min_element(candidate.begin(), candidate.end()) << endl;


}


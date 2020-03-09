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

int main() {
    int x, y;
    string w;
    cin >> x >> y >> w;
    x--;
    y--;
    vector<vector<int>> board(9, vector<int>(9));
    rep(i, 9) rep(j, 9) {
            char c;
            cin >> c;
            board[i][j] = c - '0';
        }

    auto go = [&] {
        if (w == "R") x++;
        else if (w == "D") y++;
        else if (w == "L") x--;
        else if (w == "U") y--;
        else if (w == "RU") {
            x++;
            y--;
        } else if (w == "RD") {
            x++;
            y++;
        } else if (w == "LU") {
            x--;
            y--;
        } else if (w == "LD") {
            x--;
            y++;
        } else {
            __throw_runtime_error("konai");
        }
    };

    auto is_outside = [&]() {
        if (x == -1) return true;
        if (x == 9) return true;
        if (y == -1) return true;
        if (y == 9) return true;
        return false;
    };

    auto is_over_left = [&] {
        return x == -1;
    };

    auto is_over_right = [&] {
        return x == 9;
    };

    auto is_over_up = [&] {
        return y == -1;
    };

    auto is_over_down = [&] {
        return y == 9;
    };

    auto return_left_right = [&] {
        x = 1;
        if (w == "L") w = "R";
        else if (w == "LU") w = "RU";
        else if (w == "LD") w = "RD";
    };

    auto return_right_left = [&] {
        x = 7;
        if (w == "R") w = "L";
        else if (w == "RU") w = "LU";
        else if (w == "RD") w = "LD";
    };

    auto return_up_down = [&] {
        y = 1;
        if (w == "U") w = "D";
        else if (w == "RU") w = "RD";
        else if (w == "LU") w = "LD";
    };

    auto return_down_up = [&] {
        y = 7;
        if (w == "D") w = "U";
        else if (w == "RD") w = "RU";
        else if (w == "LD") w = "LU";
    };


    auto next = [&] {
        go();
        if (!is_outside()) {
            return;
        }
        if (is_over_left()) {
            return_left_right();
        }
        if (is_over_right()) {
            return_right_left();
        }
        if (is_over_up()) {
            return_up_down();
        }
        if (is_over_down()) {
            return_down_up();
        }
    };

    for (int i = 0; i < 4; i++) {
        cout << board[y][x];
        next();
    }
    cout << endl;
}

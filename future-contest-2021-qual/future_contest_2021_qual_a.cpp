#include <bits/stdc++.h>
//#include "atcoder/all"
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;


using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

const int mod = 1000000007;

// 愚直

//


struct Robot {
    int y = 0, x = 0;

    stack<int> mountain;

    vector<vector<int>> board;

    vector<P> cards;

//    ofstream cout;

    Robot(vector<P> cards) : cards(cards) {
        board = vector<vector<int>>(100, vector<int>(100, -1));

        rep(i, 100) {
            P p = cards[i];
            board[p.first][p.second] = i;
        }

//        cout = ofstream("/home/riku/CLionProjects/atcoder/out.txt");

    }

    void go(int to_y, int to_x) {
        auto r = [&]() {
            cout << 'R';
            x++;
        };


        auto l = [&]() {
            cout << 'L';
            x--;
        };

        auto u = [&]() {
            cout << 'U';
            y--;
        };

        auto d = [&]() {
            cout << 'D';
            y++;
        };

        while (x != to_x) {
            if (x < to_x) r();
            else l();
        }

        while (y != to_y) {
            if (y < to_y) d();
            else u();
        }
    }

    void in() {
        assert(board[y][x] != -1);
        int target = board[y][x];
        board[y][x] = -1;
        cards[target] = P(-1, -1);
        mountain.push(target);
        cout << 'I';
    }


    bool has(int y, int x) {
        return board[y][x] != -1;
    }

    int get(int y, int x) {
        assert(has(y, x));
        return board[y][x];
    }

    void out() {
        assert(!has(y, x));
        assert(!mountain.empty());
        int target = mountain.top();

        mountain.pop();
        board[y][x] = target;
        cards[target] = P(y, x);

        cout << 'O';

    }

    P find(int i) {
        assert(cards[i] != P(-1, -1));
        return cards[i];
    }

};

void straight(Robot &robot) {
    rep(i, 100) {
        P p = robot.find(i);
        robot.go(p.first, p.second);
        robot.in();
    }
    cout << endl;
}


void collect_half(int mi, int ma, int start_x, int end_x, Robot &robot) {
    vector<int> ys;
    for (int y = 0; y < 20; y++) {
        ys.push_back(y);
    }

    if (abs(ys.front() - robot.y) > abs(ys.back() - robot.y)) {
        reverse(ys.begin(), ys.end());
    }

    for (int y  : ys) {

        vector<int> use;

        for (int x = start_x; x <= end_x; x++) {
            if (robot.has(y, x)) {
                int target = robot.get(y, x);
                if (mi <= target && target <= ma) {
                    use.push_back(x);
                }
            }
        }

        if (use.empty())continue;
        if (abs(use.front() - robot.x) > abs(use.back() - robot.x)) {
            reverse(use.begin(), use.end());
        }

        for (int x : use) {
            robot.go(y, x);
            robot.in();
        }
    }
}

void collect(int mi, int ma, Robot &robot) {
    collect_half(mi, ma, 0, 9, robot);
    collect_half(mi, ma, 10, 19, robot);
}

void paste(int left_x, int right_x, int start_y, int count, Robot &robot) {
    queue<P> q;
    for (int y = start_y; y < 20; y++) {
        if (y % 2 == 0) {
            for (int x = left_x; x <= right_x; x++) {
                q.push(P(y, x));
            }
        } else {
            for (int x = right_x; x >= left_x; x--) {
                q.push(P(y, x));
            }
        }
    }

    rep(_, count) {
        P p = q.front();
        q.pop();
        robot.go(p.first, p.second);
        robot.out();
    }
}


int main() {
//    ifstream cin("/home/riku/CLionProjects/atcoder/sampleInput.txt");

    vector<P> v(100);
    for (P &p:v)cin >> p.first >> p.second;

    Robot robot(v);

    collect(0, 99, robot);
    paste(0, 19, 0, 100, robot);

    collect(0, 24, robot);
    collect(25, 49, robot);
    collect(50, 74, robot);
    collect(75, 99, robot);
    paste(0, 4, 0, 25, robot);
    paste(5, 9, 5, 25, robot);
    paste(10, 14, 10, 25, robot);
    paste(15, 19, 15, 25, robot);


    straight(robot);

//    straight();


}
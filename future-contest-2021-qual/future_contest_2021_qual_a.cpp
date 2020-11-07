#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;
//#include "atcoder/all"

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

bool equal(double a, double b) {
//    return fabs(a - b) < DBL_EPSILON;
    return fabs(a - b) < EPS;
}

template<class T>
std::istream &operator>>(std::istream &in, set<T> &o) {
    T a;
    in >> a;
    o.insert(a);
    return in;
}

template<class T>
std::istream &operator>>(std::istream &in, queue<T> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

template<class T>
bool contain(set<T> &s, T a) { return s.find(a) != s.end(); }

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;


struct Robot {
    int y = 0, x = 0;

    stack<int> mountain;

    vector<vector<int>> board;

    vector<P> cards;

    ostream &cout;

    Robot(vector<P> cards, ostream &cout) : cards(cards), cout(cout) {
        board = vector<vector<int>>(100, vector<int>(100, -1));

        rep(i, 100) {
            P p = cards[i];
            board[p.first][p.second] = i;
        }

//        cout = ofstream("C:\\Users\\riku\\CLionProjects\\apg\\sample_output.txt");

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

    int nealy(vector<int> &candidate) {

        int dis = 100;

        for (int i : candidate) {
            P p = cards[i];
            assert(p != P(-1, -1));
            int now = abs(p.first - y) + abs(p.second - x);
            cmin(dis, now);
        }

        for (int i : candidate) {
            P p = cards[i];
            assert(p != P(-1, -1));
            int now = abs(p.first - y) + abs(p.second - x);
            if (now == dis) return i;
        }
        return -1;
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

/*
void collect(int mi, int ma, Robot &robot) {
    set<int> candidate;
    for (int i = mi; i <= ma; i++) if (robot.find(i) != P(-1, -1)) candidate.insert(i);
    int target = robot.nealy(candidate);
    while (target != -1) {
        P p = robot.find(target);
        robot.go(p.first, p.second);
        robot.in();
        candidate.erase(target);
        target = robot.nealy(candidate);
    }
}
*/

void collect(int mi, int ma, Robot &robot) {
    vector<int> candidate;
    for (int i = mi; i <= ma; i++) if (robot.find(i) != P(-1, -1)) candidate.push_back(i);
    vector<int> route;

    P start = P(robot.y, robot.x);

    auto distance = [&](P a, P b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    };

    auto from_back = [&](int target) -> int {
        if (route.empty()) return distance(start, robot.find(target));
        return distance(robot.find(route.back()), robot.find(target)) + distance(robot.find(target), P(19, 19));
    };

    auto before = [&](int target, int after_i) -> int {
        P prev = after_i == 0 ? start : robot.find(route[after_i - 1]);
        P after = robot.find(route[after_i]);
        P target_p = robot.find(target);

        return distance(prev, target_p) + distance(target_p, after) - distance(prev, after);

    };

    while (!candidate.empty()) {
        int target = robot.nealy(candidate);
        candidate.erase(find(candidate.begin(), candidate.end(), target));
        int mi_c = from_back(target);
        rep(i, route.size()) {
            cmin(mi_c, before(target, i));
        }

        if (from_back(target) == mi_c) {
            route.insert(route.end(), target);
        } else {
            int on = [&]() -> int {
                rep(i, route.size()) {
                    if (before(target, i) == mi_c) return i;
                }
                throw_with_nested("nai");
            }();
            route.insert(route.begin() + on, target);
        }
    }

    for (int i : route) {
        P p = robot.find(i);
        robot.go(p.first, p.second);
        robot.in();
    }

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
//    ifstream cin("C:\\Users\\riku\\CLionProjects\\apg\\sample_input.txt");
//    ofstream cout("C:\\Users\\riku\\CLionProjects\\apg\\sample_output.txt");

    vector<P> v(100);
    for (P &p:v)cin >> p.first >> p.second;

    Robot robot(v, cout);

    collect(0, 32, robot);
    collect(33, 65, robot);
    collect(66, 99, robot);
    paste(0, 5, 0, 100, robot);
//    paste(0, 5, 0, 34, robot);
//    paste(0, 5, 6, 33, robot);
//    paste(0, 5, 12, 33, robot);

//    collect(0, 49, robot);
//    collect(50, 99, robot);

//    collect(0, 24, robot);
//    collect(25, 49, robot);
//    collect(50, 74, robot);
//    collect(75, 99, robot);
//    paste(0, 4, 0, 25, robot);
//    paste(5, 9, 5, 25, robot);
//    paste(10, 14, 10, 25, robot);
//    paste(15, 19, 15, 25, robot);


    straight(robot);

//    straight();


}
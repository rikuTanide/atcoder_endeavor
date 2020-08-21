#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Next {
    P up, right, down, left;

    bool operator==(Next &o) {
        return up == o.up && right == o.right && down == o.down && left == o.left;
    }

};

P go_up(P now, map<P, Next> &mp) {

    if (mp[now].up != now) {
        return go_up(mp[now].up, mp);
    }
    P next = P(now.first + 1, now.second);
    if (mp.find(next) == mp.end()) {
        return P(now.first, now.second);
    }

    return go_up(mp[next].up, mp);

}

P go_down(P now, map<P, Next> &mp) {

    if (mp[now].down != now) {
        return go_down(mp[now].down, mp);
    }
    P next = P(now.first - 1, now.second);
    if (mp.find(next) == mp.end()) {
        return P(now.first, now.second);
    }

    return go_down(mp[next].down, mp);

}


void update_up(P now, P next_down, map<P, Next> &mp) {
    mp[now].down = next_down;

    if (mp[now].up != now) {
        update_up(mp[now].up, next_down, mp);
        return;
    }

    P next = P(now.first + 1, now.second);
    if (mp.find(next) == mp.end()) {
        return;
    }

    update_up(mp[next].up, next_down, mp);
}

void update_down(P now, P next_up, map<P, Next> &mp) {
    mp[now].up = next_up;

    if (mp[now].down != now) {
        update_down(mp[now].down, next_up, mp);
        return;
    }

    P next = P(now.first - 1, now.second);
    if (mp.find(next) == mp.end()) {
        return;
    }

    update_down(mp[next].down, next_up, mp);
}


P go_right(P now, map<P, Next> &mp) {
    assert(mp.find(now) != mp.end());
    assert(now.first == mp[now].right.first);
    assert(now.second <= mp[now].right.second);

    if (mp[now].right != now) {
        return go_right(mp[now].right, mp);
    }
    P next = P(now.first, now.second + 1);
    if (mp.find(next) == mp.end()) {
        return now;
    }

    return go_right(mp[next].right, mp);

}

P go_left(P now, map<P, Next> &mp) {
    assert(mp.find(now) != mp.end());
    if (mp[now].left != now) {
        return go_left(mp[now].left, mp);
    }
    P next = P(now.first, now.second - 1);
    if (mp.find(next) == mp.end()) {
        return now;
    }

    return go_left(mp[next].left, mp);

}

void update_right(P now, P next_left, map<P, Next> &mp) {
    mp[now].left = next_left;

    if (mp[now].right != now) {
        update_right(mp[now].right, next_left, mp);
        return;
    }

    P next = P(now.first, now.second + 1);
    if (mp.find(next) == mp.end()) {
        return;
    }

    update_right(mp[next].right, next_left, mp);
}

void update_left(P now, P next_right, map<P, Next> &mp) {
    mp[now].right = next_right;

    if (mp[now].left != now) {
        update_left(mp[now].left, next_right, mp);
        return;
    }

    P next = P(now.first, now.second - 1);
    if (mp.find(next) == mp.end()) {
        return;
    }

    update_left(mp[next].left, next_right, mp);
}

int main() {
    int k;
    string s;

    cin >> k >> s;

    map<P, Next> mp;

    auto init = [&](P next) {
        ll y = next.first;
        ll x = next.second;
        assert(mp.find(P(y, x)) == mp.end());
        mp[P(y, x)] = Next{
                P(y, x),
                P(y, x),
                P(y, x),
                P(y, x),
        };
    };

    mp[P(0, 0)] = Next{
            P(0, 0),
            P(0, 0),
            P(0, 0),
            P(0, 0)
    };

    P now = P(0, 0);

    for (char c : s) {

        if (c == 'U') {
            P limit_up = go_up(now, mp);
            P limit_down = go_down(now, mp);

            P next = P(limit_up.first + 1, now.second);

            init(next);

            update_up(now, limit_down, mp);
            update_down(now, next, mp);


            now = next;

        } else if (c == 'D') {

            P limit_up = go_up(now, mp);
            P limit_down = go_down(now, mp);

            P next = P(limit_down.first - 1, now.second);

            init(next);

            update_up(now, next, mp);
            update_down(now, limit_up, mp);


            now = next;

        } else if (c == 'R') {
            P limit_right = go_right(now, mp);
            P limit_left = go_left(now, mp);

            P next = P(now.first, limit_right.second + 1);

            init(next);

            update_right(now, limit_left, mp);
            update_left(now, next, mp);

            now = next;
        } else if (c == 'L') {
            P limit_right = go_right(now, mp);
            P limit_left = go_left(now, mp);

            P next = P(now.first, limit_left.second - 1);

            init(next);

            update_right(now, next, mp);
            update_left(now, limit_right, mp);

            now = next;
        }

    }

    printf("%lld %lld\n", now.second, now.first);


}

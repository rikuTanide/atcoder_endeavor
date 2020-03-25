#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
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


int main() {
    ll d, g;
    cin >> d >> g;

    vector<ll> questions(d), bonus(d);
    rep(i, d) cin >> questions[i] >> bonus[i];

    ll ans = INF;

    vector<ll> difficulties;
    rep(i, d) difficulties.push_back((i + 1) * 100);

    auto is_complete = [&](ll i, ll difficulty) {
        ll j = difficulty / 100 - 1;
        bool b = (i >> j) & 1;
        return b;
    };

    auto get_question_count = [&](ll difficulty) {
        ll j = difficulty / 100 - 1;
        return questions[j];
    };

    auto get_bonus = [&](ll difficulty) {
        ll j = difficulty / 100 - 1;
        return bonus[j];
    };

    auto get_minimum_score = [&](ll i) {
        ll sum = 0;
        for (ll difficulty: difficulties) {
            if (is_complete(i, difficulty)) {
                ll now = difficulty * get_question_count(difficulty) + get_bonus(difficulty);
                sum += now;
            }
        }
        return sum;
    };

    auto get_minimum_count = [&](ll i) {
        ll sum = 0;
        for (ll difficulty: difficulties) {
            if (is_complete(i, difficulty)) {
                ll now = get_question_count(difficulty);
                sum += now;
            }
        }
        return sum;
    };

    auto get_solve_questions = [&](ll difficulty, ll need_score) {
        ll questions = max(0ll, get_question_count(difficulty) - 1);
        ll need_questions = need_score / difficulty;
        return min(need_questions, questions);
    };

    auto get_add_questions = [&](ll i, ll need_score) {
        ll sum = 0;
        for (ll j = difficulties.size() - 1; j >= 0; j--) {
            if (need_score <= 0) continue;
            ll difficulty = difficulties[j];
            if (is_complete(i, difficulty)) continue;

            ll solve_questions = get_solve_questions(difficulty, need_score);
            sum += solve_questions;
            ll add_score = solve_questions * difficulty;
            need_score -= add_score;
        }
        if (need_score > 0) return -1ll;
        return sum;
    };


    for (ll i = 0; i < (1 << d); i++) {
        ll minimum_score = get_minimum_score(i);
        ll complete_questions = get_minimum_count(i);
        ll add_questions = get_add_questions(i, g - minimum_score);
        if (add_questions == -1) continue;
        ll now = complete_questions + add_questions;
        cmin(ans, now);
    }

    cout << ans << endl;

}




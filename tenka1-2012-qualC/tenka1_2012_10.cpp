#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//const ll mod = 1e10;
typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

struct Card {
    char mark;
    string number;
};

string check(vector<Card> &cards, char target) {
    set<string> need_numbers = {"10", "J", "Q", "K", "A"};
    string ans = "";
    rep(i, cards.size()) {
        if (cards[i].mark != target) {
            ans += (cards[i].mark + cards[i].number);
        } else if (need_numbers.find(cards[i].number) == need_numbers.end()) {
            ans += (cards[i].mark + cards[i].number);
        } else {
            need_numbers.erase(cards[i].number);
            if (need_numbers.empty()) break;
        }
    }
    if (!need_numbers.empty()) {
        return "-1";
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    vector<Card> cards;

    for (char c : s) {
        if (c == 'S' || c == 'H' || c == 'D' || c == 'C') {
            cards.push_back({c, ""});
        } else {
            cards.back().number += c;
        }
    }

    string ans = s;
    {
        string now = check(cards, 'S');
        if (now != "-1") {
            ans = now;
        }
    }
    {
        string now = check(cards, 'H');
        if (now != "-1") {
            if (ans.size() > now.size()) {
                ans = now;
            }
        }
    }
    {
        string now = check(cards, 'D');
        if (now != "-1") {
            if (ans.size() > now.size()) {
                ans = now;
            }
        }
    }
    {
        string now = check(cards, 'C');
        if (now != "-1") {
            if (ans.size() > now.size()) {
                ans = now;
            }
        }
    }
    if(ans == "") ans = "0";
    cout << ans << endl;
}

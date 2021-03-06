#include <bits/stdc++.h>

const double PI = 3.14159265358979323846;
using namespace std;
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

//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    k--;

    vector<int> tweets(n);
    vector<int> display_tweets(n);
    vector<set<int>> follow(n);

    map<P, ll> map;

    auto unfollow = [&](int a, int b) {
        follow[a].erase(b);
        follow[b].erase(a);

        ll db = tweets[b] - map[P(a, b)];
        ll da = tweets[a] - map[P(b, a)];

        display_tweets[a] += db;
        display_tweets[b] += da;
    };

    rep(_, m) {
        char method;
        cin >> method;
        if (method == 't') {
            int a;
            cin >> a;
            a--;

            tweets[a]++;

        } else if (method == 'f') {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            follow[a].insert(b);
            follow[b].insert(a);

            map[P(a, b)] = tweets[b];
            map[P(b, a)] = tweets[a];


        } else {

            int a, b;
            cin >> a >> b;
            a--;
            b--;
            unfollow(a, b);
        }
    }


    set<P> c;
    rep(i, n) {
        for (int t : follow[i]) c.insert(P(min(i, t), max(i, t)));
    }

    for (P p : c) {
        unfollow(p.first, p.second);
    }

    rep(i, n) display_tweets[i] += tweets[i];

    sort(display_tweets.rbegin(), display_tweets.rend());

    cout << display_tweets[k] << endl;
}

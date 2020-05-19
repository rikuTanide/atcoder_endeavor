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

class Contest {
    multiset<ll> start, end;
public:
    void push(ll l, ll r) {
        start.insert(l);
        end.insert(r);
    }

    void pop(ll l, ll r) {
        start.erase(start.find(l));
        end.erase(end.find(r));
    }

    ll count() {
        ll l = *start.rbegin();
        ll r = *end.begin();
        if (r < l) return 0;
        ll now = r - l + 1;

        return now;
    }

};

ll max_range(vector<P> &questions) {
    ll k = 0;
    for (P p: questions) cmax(k, p.second - p.first + 1);
    return k;
}

int main() {

//    ifstream file("C:\\Users\\riku\\Downloads\\01-16.txt");

    int n;
    cin >> n;
    vector<P> questions(n);
    rep(i, n) cin >> questions[i].first >> questions[i].second;

    P l = *min_element(questions.begin(), questions.end(), [](P p1, P p2) { return p1.second < p2.second; });
    P r = *max_element(questions.begin(), questions.end(), [](P p1, P p2) { return p1.first < p2.first; });

    if (l == r) {
        cout << max_range(questions) << endl;
        ret();
    }

//    assert(l != r);
//    assert(l.second <= r.first);

    Contest c1, c2;
    c1.push(l.first, l.second);
    c2.push(r.first, r.second);

    vector<P> tmp;
    for (P p : questions)
        if (p == l || p == r) continue;
        else tmp.push_back(P(p.first, -p.second));

    sort(tmp.begin(), tmp.end());
    for (P &p : tmp) p.second = -p.second;


    for (P p : tmp) c2.push(p.first, p.second);

    ll ans = max_range(questions);


    cmax(ans, c1.count() + c2.count());
//    cout << c1.count() + c2.count() << endl;

    for (P p : tmp) {
        c1.push(p.first, p.second);
        c2.pop(p.first, p.second);
        cmax(ans, c1.count() + c2.count());
//        cout << c1.count() + c2.count() << endl;
    }
    cout << ans << endl;

}
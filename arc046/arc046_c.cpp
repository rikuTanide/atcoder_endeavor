#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

struct Boy {
    ll salary, border;
};

struct Girl {
    ll salary, border;
};

struct Participant {
    char gender;
    int index;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Boy> boys(n);
    vector<Girl> girls(m);
    for (Boy &b : boys) cin >> b.salary >> b.border;
    for (Girl &g : girls) cin >> g.salary >> g.border;

    vector<Participant> participants;
    rep(i, n) participants.push_back(Participant{'b', i});
    rep(i, m) participants.push_back(Participant{'g', i});

    sort(participants.begin(), participants.end(), [&](Participant p1, Participant p2) {

        auto f = [&](Participant p) -> vector<ll> {
            if (p.gender == 'b') {
                Boy b = boys[p.index];
                return {b.salary, 1};
            } else {
                Girl g = girls[p.index];
                return {g.border, 0};
            }
        };

        auto v = f(p1);
        auto u = f(p2);

        return v < u;

    });

    multiset<ll> waiting;

    int ans = 0;

    for (Participant p : participants) {
        if (p.gender == 'b') {
            Boy b = boys[p.index];

            auto it = waiting.lower_bound(b.border);
            if (it == waiting.end()) continue;
            else {
                waiting.erase(it);
                ans++;
            }
        } else {
            Girl g = girls[p.index];
            waiting.insert(g.salary);
        }
    }

    cout << ans << endl;
}
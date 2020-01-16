#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

P minu(P p, P q) {
    return P(p.first - q.first, p.second - q.second);
}

bool cross_vec(P p, P q) {
    return (p.first * q.second - p.second * q.first) < 0;
}

vector<P> graham_scan(vector<P> &cosmos) {

    P start = accumulate(cosmos.begin(), cosmos.end(), cosmos[0], [](P &p, P &q) {
        if (p.second < q.second) return p;
        if (p.second > q.second) return q;
        if (p.first < q.first) return p;
        return q;
    });

    sort(cosmos.begin(), cosmos.end(), [&](P &p, P &q) {
        if (start == p) return true;
        if (start == q) return false;

        P pa(p.first - start.first, p.second - start.second);
        P qa(q.first - start.first, q.second - start.second);

        double pat = atan2(pa.second, pa.first);
        double qat = atan2(qa.second, qa.first);
        return pat < qat;
    });

    assert(cosmos[0] == start);

    vector<int> path(cosmos.size());

    int k = 0;

    rep(i, cosmos.size()) {
        while (true) {
            if (k < 2) break;

            P current_p = cosmos[path[k - 1]];
            P back_p = cosmos[path[k - 2]];
            P next_p = cosmos[i];

            P current = minu(current_p, back_p);
            P next = minu(next_p, back_p);

            bool b = cross_vec(current, next);
            if (b) {
                k--;
            } else {
                break;
            }
        }
        path[k] = i;
        k++;
    }

    path.resize(k);
    vector<P> p_route(path.size());
    rep(i, path.size()) p_route[i] = cosmos[path[i]];
    p_route.push_back(start);
    return p_route;

}

double calc_outer(vector<P> &cosmos) {
    double ans = 0;

    rep(i, cosmos.size() - 1) {
        P p = cosmos[i];
        P q = cosmos[i + 1];

        ll x = p.first - q.first;
        ll y = p.second - q.second;

        ll xx = x * x;
        ll yy = y * y;
        ans += sqrt(xx + yy);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<P> cosmos(n);
    rep(i, n) {
        cin >> cosmos[i].first;
        cin >> cosmos[i].second;
    }

    vector<P> i_g = graham_scan(cosmos);

    vector<P> cosmos2(n);
    rep(i, n) {
        cin >> cosmos2[i].first;
        cin >> cosmos2[i].second;
    }

    vector<P> s_g = graham_scan(cosmos2);

    double i_o = calc_outer(i_g);
    double s_o = calc_outer(s_g);


    printf("%.20f\n", s_o / i_o);


}

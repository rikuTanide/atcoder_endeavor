#include <bits/stdc++.h>
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

int main() {


    // 最小本数
    // 最大本数

    // 桁数

    // 桁目を何にしたか
    // 残り


    // 大きい順に優先
    // 残り桁数＊最小本数＜＝残り本数＆＆残り桁数＊最大本数＞＝残り本数なら可能

    map<int, int> u = {
            {1, 2},
            {2, 5},
            {3, 5},
            {4, 4},
            {5, 5},
            {6, 6},
            {7, 3},
            {8, 7},
            {9, 6},
    };

    int n, m;
    cin >> n >> m;

    vector<int> v(m);
    rep(i, m) cin >> v[i];
    sort(v.rbegin(), v.rend());

    int mi = INT_MAX;
    for (int i : v) cmin(mi, u[i]);
    int ma = 0;
    for (int i : v) cmax(ma, u[i]);

    int k = n / mi;

    while (true) {

        vector<int> dp_ans(k);
        vector<int> dp_rem(k);

        rep(i, k) {
            int back_rem = i == 0 ? n : dp_rem[i - 1];
            for (int j : v) {
                int use = u[j];
                int next_rem = back_rem - use;
                int nokori_keta = k - i - 1;
                bool tariru = nokori_keta * mi <= next_rem;
                bool tukaikireru = nokori_keta * ma >= next_rem;

                if (tariru && tukaikireru) {
                    dp_ans[i] = j;
                    dp_rem[i] = next_rem;
                    break;
                }
            }
        }

        if (dp_rem.back() == 0) {
            rep(i, k) cout << dp_ans[i];
            cout << endl;
            return 0;
        } else {
            k--;
        }


    }
}

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


template<class T>
void combination(const vector<T> &seed, int target_size, function<bool(const vector<int> &)> callback) {
    vector<int> indices(target_size);
    const int seed_size = seed.size();
    int start_index = 0;
    int size = 0;

    while (size >= 0) {
        for (int i = start_index; i < seed_size; ++i) {
            indices[size++] = i;
            if (size == target_size) {
                vector<T> comb(target_size);
                for (int x = 0; x < target_size; ++x) {
                    comb[x] = seed[indices[x]];
                }
                if (callback(comb)) return;
                break;
            }
        }
        --size;
        if (size < 0) break;
        start_index = indices[size] + 1;
    }
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<ll> fs(n);
    rep(i, n)cin >> fs[i];

    vector<int> vals;
    rep(i, n) vals.push_back(i);

    ll ans = INF;

    function<bool(const vector<int> &)> my_callback = [&](const vector<int> &comb) -> bool {

        ll sum = 0;
        for (int f : comb) {
            sum += fs[f];
        }

        ll coins = 0;
        while (sum > 0) {
            ll t = sum % 10;
            if (t >= 5) {
                coins++;
                t -= 5;
            }
            coins += t;
            sum /= 10;
        }
        cmin(ans, coins);
        return false;
    };


    combination(vals, k, my_callback);
    cout << ans << endl;
}

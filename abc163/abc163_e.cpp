#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
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

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

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
const int mod = 1000000007;


struct Infant {
    ll index;
    ll active;
};

int main() {
    int n;
    cin >> n;

    vector<Infant> infants(n);
    rep(i, n) infants[i].index = i;
    rep(i, n) cin >> infants[i].active;

//
//    vector<int> arr(n);
//    rep(i, n)arr[i] = i;
//    ll ma = 0;
//    do {
//        for (int i : arr) cout << infants[i].active;
//        cout << ' ';
//        vector<Infant> target(n);
//        rep(i, n) target[i] = infants[arr[i]];
//
//        ll ans = 0;
//        rep(i, n) {
//            Infant infant = target[i];
//            ll diff = abs(infant.index - i);
//            ll now = infant.active * diff;
//            ans += now;
//        }
//        cout << ans << endl;
//        cmax(ma, ans);
//
//    } while (std::next_permutation(arr.begin(), arr.end()));
//    cout << ma << endl;
//

    vector<Infant> target(n);


    queue<int> q;
    {
        int left = 0;
        int right = n - 1;

        while (left < right) {
            q.push(left);
            q.push(right);
            left++;
            right--;
        }
        if (n % 2 == 1) q.push(n / 2);
    }

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        ll ma = -1;
        ll ma_i = -1;
        rep(i, infants.size()) {
            Infant infant = infants[i];
            ll score = abs(t - infant.index) * infant.active;
            if (score > ma) {
                ma = score;
                ma_i = i;
            }
        }

        target[t] = infants[ma_i];
        infants.erase(infants.begin() + ma_i);
    }
    ll ans = 0;
    rep(i, n) {
        Infant infant = target[i];
        ll diff = abs(infant.index - i);
        ll now = infant.active * diff;
        ans += now;
    }
    cout << ans << endl;
}


#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
typedef tuple<int, int, int> Q;

ll culcAbs(ll s1, ll s2, ll s3, ll s4) {
    ll mi = s1;
    mi = min(s2, mi);
    mi = min(s3, mi);
    mi = min(s4, mi);

    ll ma = s1;
    ma = max(s2, ma);
    ma = max(s3, ma);
    ma = max(s4, ma);
    return ma - mi;
}

int cutLeft(int center, vector<ll> &numbers, vector<ll> &sums) {

    int l = 1;
    int r = center - 1;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        ll lsum = sums[mid];
        ll rsum = sums[center] - sums[mid];

        if (lsum > rsum) {
            r = mid;
        } else {
            l = mid;
        }


    }

    ll lans;
    ll rans;

    {
        ll lsum =  sums[l];
        ll rsum = sums[center] - sums[l];
        lans = abs(lsum - rsum);

    }

    {
        ll lsum =  sums[r];
        ll rsum = sums[center] - sums[r];
        rans = abs(lsum - rsum);

    }

    if (lans < rans) {
        return l;
    } else {
        return r;
    }

}

int cutRight(int center, vector<ll> &numbers, vector<ll> &sums) {

    int l = center + 1;
    int r = numbers.size() - 1;

    while (r - l > 1) {
        int mid = (l + r) / 2;
        ll lsum = sums[mid] - sums[center];
        ll rsum = sums.back() - sums[mid];

        if (lsum > rsum) {
            r = mid;
        } else {
            l = mid;
        }

    }

    ll lans;
    ll rans;

    ll sumsl = sums[l];
    ll sumsr = sums[r];
    ll sums_back = sums.back();
    ll sums_center = sums[center];
    {
        ll lsum = sumsl - sums_center;
        ll rsum = sums_back - sumsl;
        lans = abs(lsum - rsum);

    }

    {
        ll lsum = sumsr - sums_center;
        ll rsum = sums_back - sumsr;
        rans = abs(lsum - rsum);
    }

    if (lans < rans) {
        return l;
    } else {
        return r;
    }


}

ll centerCut(int center, vector<ll> &numbers, vector<ll> &sums) {
    ll left = cutLeft(center, numbers, sums);
    ll right = cutRight(center, numbers, sums);
/*
    for (int i = 0; i < left; i++) {
        cout << numbers[i] << ' ';
    }
    cout << '/';

    for (int i = left; i < center; i++) {
        cout << numbers[i] << ' ';
    }
    cout << '/';

    for (int i = center; i < right; i++) {
        cout << numbers[i] << ' ';
    }
    cout << '/';
    for (int i = right; i < numbers.size(); i++) {
        cout << numbers[i] << ' ';
    }


    cout << '#' << now;

    cout << endl;

*/

    ll s1 = sums[left];
    ll s2 = sums[center] - s1;
    ll s3 = sums[right] - s1 - s2;
    ll s4 = sums.back() - s1 - s2 - s3;

    if (s1 == 0 || s2 == 0 || s3 == 0 || s4 == 0) {
        return INF;
    }

    ll now = culcAbs(s1, s2, s3, s4);


    return now;

}

int main() {
    int n;
    cin >> n;
    vector<ll> numbers(n);
    rep(i, n) {
        cin >> numbers[i];
    }

    vector<ll> sums(n + 1, 0);

    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + numbers[i];
    }
    ll ans = INF;
//            ans = min(ans, centerCut(4, numbers, sums));
//
    for (int i = 2; i <= n - 2; i++) {

        ans = min(ans, centerCut(i, numbers, sums));

    }

    cout << ans << endl;

}



#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
//const int INF = INT_MAX  ;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;

typedef tuple<ll, int, int, int> PC;

int main() {

    int x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<ll> xl(x);
    vector<ll> yl(y);
    vector<ll> zl(z);

    rep(i, x) {
        ll nx;
        cin >> nx;
        xl[i] = nx;
    }

    rep(i, y) {
        ll ny;
        cin >> ny;
        yl[i] = ny;
    }


    rep(i, z) {
        ll nz;
        cin >> nz;
        zl[i] = nz;
    }
    sort(xl.rbegin(), xl.rend());
    sort(yl.rbegin(), yl.rend());
    sort(zl.rbegin(), zl.rend());

    cout << xl[0] + yl[0] + zl[0] << endl;

    priority_queue<PC> staging;

    staging.emplace(xl[1] + yl[0] + zl[0], 1, 0, 0);
    staging.emplace(xl[0] + yl[1] + zl[0], 0, 1, 0);
    staging.emplace(xl[0] + yl[0] + zl[1], 0, 0, 1);

    set<PC> st;

    for (int i = 0; i < k - 1; i++) {
        auto top = staging.top();
        staging.pop();
        ll now = get<0>(top);
        int cx = get<1>(top);
        int cy = get<2>(top);
        int cz = get<3>(top);

        if (cx < x - 1) {
            int nx = cx + 1;
            int ny = cy;
            int nz = cz;
            PC p(xl[nx] + yl[ny] + zl[nz], nx, ny, nz);
            if (st.find(p) == st.end()) {
                st.insert(p);
                staging.emplace(p);
            }
        }

        if (cy < y - 1) {
            int nx = cx;
            int ny = cy + 1;
            int nz = cz;
            PC p(xl[nx] + yl[ny] + zl[nz], nx, ny, nz);
            if (st.find(p) == st.end()) {
                st.insert(p);
                staging.emplace(p);
            }
        }

        if (cz < z - 1) {
            int nx = cx;
            int ny = cy;
            int nz = cz + 1;
            PC p(xl[nx] + yl[ny] + zl[nz], nx, ny, nz);
            if (st.find(p) == st.end()) {
                st.insert(p);
                staging.emplace(p);
            }
        }

        cout << now << endl;

    }


}


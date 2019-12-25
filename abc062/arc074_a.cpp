#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

struct FirstSplit {
    ll first_w, first_h;
    ll second_w, second_h;
};

struct SecondSplit {
    ll first_w, first_h;
    ll second_w, second_h;
    ll third_w, third_h;
};


int main() {


    vector<FirstSplit> first_splits;
    vector<SecondSplit> second_splits;


    ll h, w;
    cin >> h >> w;

    if (h % 3 == 0 || w % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = h * w;
    ll about = sum / 3;

    // 左右に1/3ずつと1/3+1ずつ

    {
        ll sw = w / 3;
        FirstSplit fs = {sw, h, w - sw, h};
        first_splits.push_back(fs);
    }
    {
        ll sw = w / 3 + 1;
        FirstSplit fs = {sw, h, w - sw, h};
        first_splits.push_back(fs);
    }

    {
        ll sh = h / 3;
        FirstSplit fs = {w, sh, w, h - sh};
        first_splits.push_back(fs);
    }
    {
        ll sh = h / 3 + 1;
        FirstSplit fs = {w, sh, w, h - sh};
        first_splits.push_back(fs);
    }

    for (FirstSplit fs : first_splits) {

        /*
         *     ll first_w, first_h;
    ll second_w, second_h;
    ll third_w, third_h;
         */

        // 左右に1/2ずつと1/2+1ずつ
        {
            ll sw = fs.second_w / 2;
            SecondSplit ss = {fs.first_w, fs.first_h, sw, fs.second_h, fs.second_w - sw, fs.second_h};
            second_splits.push_back(ss);
        }
        {
            ll sw = fs.second_w / 2 + 1;
            SecondSplit ss = {fs.first_w, fs.first_h, sw, fs.second_h, fs.second_w - sw, fs.second_h};
            second_splits.push_back(ss);
        }
        {
            ll sh = fs.second_h / 2;
            SecondSplit ss = {fs.first_w, fs.first_h, fs.second_w, sh, fs.second_w, fs.second_h - sh};
            second_splits.push_back(ss);
        }
        {
            ll sh = fs.second_h / 2 + 1;
            SecondSplit ss = {fs.first_w, fs.first_h, fs.second_w, sh, fs.second_w, fs.second_h - sh};
            second_splits.push_back(ss);
        }
    }


    ll ans = INF;
    for (SecondSplit sp : second_splits) {

        ll f = sp.first_h * sp.first_w;
        ll s = sp.second_h * sp.second_w;
        ll t = sp.third_h * sp.third_w;

        if (f + s + t != h * w) {
            cout << endl;
        }
        assert(f + s + t == h * w);

        vector<ll> all = {f, s, t};
        sort(all.begin(), all.end());
        if (all[0] == 0) continue;
        ll diff = all[2] - all[0];
        cmin(ans, diff);
    }

    cout << ans << endl;

}


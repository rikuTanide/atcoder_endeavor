#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

struct Rain {
    int sh, sm, eh, em;
};

bool before(Rain next, Rain back) {
    if (back.eh > next.sh) {
        return true;
    }
    if (back.eh < next.sh) {
        return false;
    }
    if (back.em >= next.em) {
        return true;
    }
    return false;
}

Rain endMax(Rain next, Rain back) {
    if (back.eh < next.eh) {
        return next;
    }
    if (back.eh > next.eh) {
        return back;
    }
    if (back.em >= next.em) {
        return back;
    }
    return next;
}


int main() {
    int n;
    cin >> n;
    vector<Rain> rains(n);

    rep(i, n) {
        char m;
        int s, e;
        cin >> s >> m >> e;

        int sh = s / 100;
        int sm = s % 100;
        sm = sm / 5 * 5;

        int eh = e / 100;
        int em = e % 100;
        em = (em + 4) / 5 * 5;
        if (em == 60) {
            em = 0;
            eh++;
        }

        rains[i].sh = sh;
        rains[i].sm = sm;
        rains[i].eh = eh;
        rains[i].em = em;
    }

    sort(rains.begin(), rains.end(), [](Rain r, Rain s) {
        if (r.sh < s.sh) {
            return true;
        }
        if (r.sh > s.sh) {
            return false;
        }
        return r.sm < s.sm;
    });

    vector<Rain> ans;
    ans.push_back(rains[0]);

    for (int i = 1; i < n; i++) {
        Rain back = ans.back();
        Rain next = rains[i];
        if (before(next, back)) {
            Rain end = endMax(next, back);
            ans.back().eh = end.eh;
            ans.back().em = end.em;
        } else {
            ans.push_back(next);
        }
    }

    for (Rain r : ans) {
        printf("%02d%02d-%02d%02d\n", r.sh, r.sm, r.eh, r.em);
    }

}

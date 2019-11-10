#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1001001001;

const int mod = 1000000007;

int main() {
    string s;

    cin >> s;

    map<char, int> m;

    for (int i = 0; i < 4; i++) {
        char c = s[i];
        m[c]++;
    }

    if (m.size() == 2 && (*m.begin()).second == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


}
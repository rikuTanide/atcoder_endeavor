#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int n;

    cin >> n;
    int n2 = 1 << n;

    vector<int> a(n2);

    rep(i, n2) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> s;
    s.push_back(a.back());
    a.back() = -1;

    rep(i, n) {
        vector<int> p = s;
        sort(p.begin(), p.end());
        int ai = n - 1;
        while (p.size() > 0 && ai >= 0) {
            if (a[ai] == -1) {
                ai--;
                continue;
            }
            if (a[ai] < p.back()) {
                s.push_back(p.back());
                p.pop_back();
            }
            ai--;
        }
        if (p.size() > 0) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}

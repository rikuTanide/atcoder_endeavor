#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;


int main() {

    set<char> odd = {'R', 'U', 'D'};
    set<char> even = {'L', 'U', 'D'};

    string line;
    cin >> line;

    bool is_odd = true;
    for (char c : line) {
        if (is_odd) {
            if (odd.find(c) == odd.end()) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (even.find(c) == even.end()) {
                cout << "No" << endl;
                return 0;
            }
        }
        is_odd = !is_odd;
    }

    cout << "Yes" << endl;

}

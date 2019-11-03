#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;


int main() {

    int n, k, q;

    cin >> n >> k >> q;


    vector<int> points = vector<int>(n);

    rep(i, q) {
        int a;
        cin >> a;
        a --;
        points[a] ++;
    }

    int dead_line = q - k;

    for(int point : points ) {
        if(point <= dead_line) {
            cout << "No" << endl;
        }else {
            cout << "Yes" << endl;
        }
    }


}

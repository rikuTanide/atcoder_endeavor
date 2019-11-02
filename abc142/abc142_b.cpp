#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;

    rep(i, n)  {
        int h;
        cin >>h ;
        if( h >= k) {
            count ++;
        }
    }

    cout << count << endl;




}

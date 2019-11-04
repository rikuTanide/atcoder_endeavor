#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;

int main() {

    int a, b;
    cin >> a >> b;

    int tap = 0;
    int socket = 1;
    while (socket < b) {
        tap++;
        socket += (a - 1);
    }
    cout << tap << endl;
}

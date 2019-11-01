#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {

    int n;
    cin >> n;

    vector<char> colors(n);

    rep(i, n) {
        char c;
        cin >> c;
        colors[i] = c;
    }

    char a = ' ';
    int count = 0;
    for (char c : colors) {
        if (c != a) {
            count++;
            a = c;
        }
    }

    cout << count << endl;

}


#include <bits/stdc++.h>

bool check(int count);

using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;

    if (a <= 9 && b <= 9) {
        cout << a * b << endl;
        return 0;
    }
    cout << -1 << endl;


}

#include <bits/stdc++.h>

bool check(int n);

using namespace std;

int main() {
    int n;
    cin >> n;

    bool b = check(n);
    cout << (b ? "Yes" : "No") << endl;
}

bool check(int n) {
    if (n > 81) {
        return false;
    }

    for (int i = 1; i <= 9; i++) {
        if (n % i == 0) {
            return true;
        }
    }
    return false;
}

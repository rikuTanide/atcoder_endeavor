#include <bits/stdc++.h>

using namespace std;

uint64_t calcPrimeFactors(uint64_t n) {
    uint64_t s = sqrt(n);
    for (uint64_t x = s; x >= 1; x--) {
        if (n % x == 0) {
            uint64_t ref = n / x;
            return ref + x;
        }
    }
    return 0;
}

int main() {
    uint64_t n;
    cin >> n;

    uint64_t m = calcPrimeFactors(n);

    cout << m - 2 << endl;

}

#include <bits/stdc++.h>

using namespace std;

int main() {
    uint64_t n, k;
    cin >> n;
    cin >> k;

    vector<uint64_t > costs(n);
    vector<uint64_t > difficults(n);
    vector<uint64_t > times(n);



    for (uint64_t j = 0; j < n; j++) {
        cin >> costs.at(j);
    }

    int sum = std::accumulate(costs.begin(), costs.end(), 0);
    if(sum <= k) {
        cout << 0 << endl;
        return 0;
    }

    for (uint64_t j = 0; j < n; j++) {
        cin >> difficults.at(j);
    }

    sort(costs.begin(), costs.end());
    sort(difficults.begin(), difficults.end(), greater<uint64_t >());

    for (uint64_t j = 0; j < n; j++) {
        times.at(j) = costs.at(j) * difficults.at(j);
    }

    for (uint64_t i = 0; i < k; i++) {
        uint64_t max = 0;
        uint64_t cause = 0;
        for (uint64_t j = 0; j < n; j++) {
            uint64_t time = times.at(j);
            if (time > max) {
                max = time;
                cause = j;
            }
        }

        uint64_t cost = costs.at(cause);
        uint64_t difficult = difficults.at(cause);
        if (cost == 0) {
            cout << 0 << endl;
            return 0;
        }
        cost--;
        times.at(cause) = cost * difficult;
        costs.at(cause) = cost;

    }

    uint64_t max = 0;
    for (uint64_t j = 0; j < n; j++) {
        uint64_t time = times.at(j);
        if (time > max) {
            max = time;
        }
    }
    cout << max << endl;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> costs(n);
    vector<int> difficults(n);
    vector<int> times(n);

    for (int j = 0; j < n; j++) {
        cin >> costs.at(j);
    }

    for (int j = 0; j < n; j++) {
        cin >> difficults.at(j);
    }

    sort(costs.begin(), costs.end());
    sort(difficults.begin(), difficults.end(), greater<int>());

    for (int j = 0; j < n; j++) {
        times.at(j) = costs.at(j) * difficults.at(j);
    }

    for (int i = 0; i < k; i++) {
        int max = 0;
        int cause = 0;
        for (int j = 0; j < n; j++) {
            int time = times.at(j);
            if (time > max) {
                max = time;
                cause = j;
            }
        }

        int cost = costs.at(cause);
        int difficult = difficults.at(cause);
        if (cost == 0) {
            cout << 0 << endl;
            return 0;
        }
        cost--;
        times.at(cause) = cost * difficult;
        costs.at(cause) = cost;

    }

    int max = 0;
    for (int j = 0; j < n; j++) {
        int time = times.at(j);
        if (time > max) {
            max = time;
        }
    }
    cout << max << endl;
}

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

    for (int j = 0; j < k; j++) {
        auto maxIt = std::max_element(times.begin(), times.end());
        int maxIndex = std::distance(times.begin(), maxIt);
        int cost = costs.at(maxIndex);
        if (cost > 0) {
            costs.at(maxIndex) = cost - 1;
            times.at(maxIndex) = (cost - 1) * difficults.at(maxIndex);
        }
    }
    auto maxIt = std::max_element(times.begin(), times.end());
    int maxIndex = std::distance(times.begin(), maxIt);

    int max = times.at(maxIndex);
    cout << max << endl;

}

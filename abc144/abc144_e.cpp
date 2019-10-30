#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> costs(n);
    vector<int> difficults(n);
    vector<int> times(n);
    vector<int> times_work(n);

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
        times_work.at(j) = costs.at(j) * difficults.at(j);
    }

    for (;;) {
        sort(times_work.begin(), times_work.end(), greater<int>());
        auto ite = std::find(times.begin(), times.end(), times_work.at(0));
        int cause = distance( times.begin(), ite );
        int cost = costs.at(cause);
        if (cost == 0) {
            cout << 0 << endl;
            return 0;
        }
        for (;;) {
            cost--;
            k--;
            costs.at(cause) = cost;
            int max = cost * difficults.at(cause);
            times.at(cause) = max;
            times_work.at(0) = max;
            if (k == 0) {
                sort(times_work.begin(), times_work.end(), greater<int>());
                cout << times_work.at(0) << endl;
                return 0;
            }
            if (times_work.at(0) < times_work.at(1)) {
                break;
            }

        }
    }

}

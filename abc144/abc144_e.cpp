#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;

    vector<int> costs(n);
    vector<int> difficults(n);

    sort(costs.begin(), costs.end());
    sort(difficults.begin(), difficults.end(), greater<int>());

    for (int j = 0; j < n; j++) {
        cin >> costs.at(j);
    }

    for (int j = 0; j < n; j++) {
        cin >> difficults.at(j);
    }

    for (int j = 0; j < k; j++) {
        int max = 0;
        int cause = 0;
        for (int i = 0; i < n; i++) {
            int time = costs.at(i) * difficults.at(i);
            if (time > max) {
                max = time;
                cause = i;
            }
        }
        costs.at(cause)--;
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        int time = costs.at(i) * difficults.at(i);
        if (time > max) {
            max = time;
        }
    }

    cout << max << endl;

}

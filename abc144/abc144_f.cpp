#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> tos(n);
    rep(i, m) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        tos[from].push_back(to);
    }

    vector<double> expected_values(n);

    for (int from = n - 2; from >= 0; from--) {
        double expected_value = 0.0;
        for (int to : tos[from]) {
            expected_value += expected_values[to];
        }
        expected_value = expected_value / tos[from].size();
        expected_value++;
        expected_values[from] = expected_value;
    }

    double ans = expected_values[0];

    for (int from = 0; from < n - 1; from++) {
        if (tos[from].size() == 1) {
            continue;
        }
        int max_to = tos[from][0];
        double max_ev = expected_values[max_to];
        for (int to : tos[from]) {

            if (expected_values[to] > max_ev) {
                max_ev = expected_values[to];
                max_to = to;
            }
        }
        // from -> max_toの道を切ればいいことが分かる

        int cut_from = from, cut_to = max_to;

        double shortness = [&]() {
            vector<double> expected_values(n);
            for (int from = n - 2; from >= 0; from--) {
                double expected_value = 0.0;
                for (int to : tos[from]) {
                    if (from == cut_from && to == cut_to) {
                        continue;
                    }
                    expected_value += expected_values[to];
                }
                int size = tos[from].size();
                if (from == cut_from) {
                    size--;
                }
                expected_value = expected_value / size;
                expected_value++;
                expected_values[from] = expected_value;
            }
            return expected_values[0];
        }();

        ans = min(ans, shortness);
    }

    printf("%.10f\n", ans);

}


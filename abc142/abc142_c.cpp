#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> students = vector<vector<int>>(n, vector<int>(2, 0));

    rep(i, n) {
        int c;
        cin >> c;

        students[i][0] = i;
        students[i][1] = c;


    }

    sort(students.begin(), students.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });

    rep(i, n) {
        cout << students[i][0] + 1 << endl;
    }


}

#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = LONG_LONG_MAX;
const ll MINF = LONG_LONG_MIN;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
//const int mod = 1000000007;
const ll mod = INF / 1000;


class Checker {
public:
    virtual bool check(int i) = 0;
};


const string TRUE_TO_FALSE = "true to false";
const string FALSE_TO_TRUE = "false to true";

class BinarySearch {
    Checker &checker;
    string orientation;

    int min_element;
    int max_element;

    int left_max;
    int right_min;


public:


    BinarySearch(Checker &checker, int min_element, int max_element, string orientation) : checker(checker),
                                                                                           min_element(min_element),
                                                                                           max_element(max_element),
                                                                                           orientation(orientation) {
        assert(orientation == TRUE_TO_FALSE || orientation == FALSE_TO_TRUE);
    }

    bool isLeftOfStart() {
        bool b = checker.check(min_element);
        if (orientation == TRUE_TO_FALSE) {
            return b == false;
        } else {
            return b == true;
        }
    }

    bool isRightOfEnd() {
        bool b = checker.check(max_element);
        if (orientation == TRUE_TO_FALSE) {
            return b == true;
        } else {
            return b == false;
        }
    }

    void search() {

        int ceil = max_element;
        int floor = min_element;

        while (floor + 1 < ceil) {
            int mid = (ceil + floor) / 2;
            int b = checker.check(mid);
            if (orientation == TRUE_TO_FALSE) {
                if (b) {
                    floor = mid;
                } else {
                    ceil = mid;
                }
            } else {
                if (b) {
                    ceil = mid;
                } else {
                    floor = mid;
                }
            }
        }
        left_max = floor;
        right_min = ceil;
    }

    int getLeftMax() {
        return left_max;
    }

    int getRightMin() {
        return right_min;
    }


};


bool checkDp(int n, int k, ll target, vector<ll> &as) {
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    dp[0][0] = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i + 1][j] = dp[i + 1][j] || dp[i][j];
            if (j >= as[i]) dp[i + 1][j] = dp[i + 1][j] || dp[i][j - as[i]];
        }
    }
    for (int i = max(0ll, k - target); i < k; i++) {
//        cout << i << ' ';
        if (dp[n][i]) {
//            cout << endl;
            return true;
        };
    }
//    cout << endl;
    return false;
}

bool checkF(int n, int k, int target_index, vector<ll> &as) {
    vector<ll> numbers(n - 1);
    for (int i = 0; i < n; i++) {
        if (i == target_index) continue;
        int j = i;
        if (i > target_index) j--;
        numbers[j] = as[i];
    }

    return checkDp(n - 1, k, as[target_index], numbers);

}

class Check : public Checker {
    int n, k;
    vector<ll> &numbers;
public:
    Check(int n, int k, vector<ll> &numbers) : n(n), k(k), numbers(numbers) {}

    bool check(int i) {
        return checkF(n, k, i, numbers);
    }
};


int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> numbers(n);
    rep(i, n) cin >> numbers[i];

    sort(numbers.rbegin(), numbers.rend());

    Check checker(n, k, numbers);

    BinarySearch bs(checker, 0, n - 1, TRUE_TO_FALSE);

    if (bs.isLeftOfStart()) {
        cout << n << endl;
        return 0;
    }
    if (bs.isRightOfEnd()) {
        cout << 0 << endl;
        return 0;
    }
    bs.search();
    cout << n - (bs.getLeftMax() + 1) << endl;

}

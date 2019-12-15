#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

int maxElement(vector<int> &counter) {
    return *max_element(counter.begin(), counter.end());
}

int checkRecursive(vector<int> &counter) {
    assert(counter.size() >= 2);
    if (counter.size() == 2) return maxElement(counter);

    int ans = 0;
    for (int i = 0; i < counter.size() - 1; i++) {
        int now = counter[i] + counter[i + 1];
        cmax(ans, now);
    }
    return ans;
}

int main() {

    string s;

    cin >> s;

    vector<int> counter;
    {
        char before = s[0];
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (before == s[i]) {
                count++;
            } else {
                before = s[i];
                counter.push_back(count);
                count = 1;
            }
        }
        counter.push_back(count);
    }
    if (counter.size() == 1) {
        cout << counter[0] << endl;
        return 0;
    }

    int ans = checkRecursive(counter);

    cout << ans << endl;
}
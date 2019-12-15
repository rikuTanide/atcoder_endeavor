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

int checkRecursive(vector<int> &counter, int size, int start, int end) {
    assert(counter.size() >= 2);

    if (start + 1 == end) return max(counter[start], counter[end]);

    if (counter[start] > counter[end]) {
        counter[start + 1] += counter[start];
        counter[start] = 0;
        return checkRecursive(counter, size, start + 1, end);
    } else {
        counter[end - 1] += counter[end];
        counter[end] = 0;
        return checkRecursive(counter, size, start, end - 1);
    }

}

int main() {

//    ifstream myfile("C:\\Users\\riku\\Downloads\\16.txt");
//    ofstream outfile("log.txt");


    string s;

    cin >> s;
//    myfile >> s;

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

//    for (int i : counter) {
//        outfile << i << endl;
//    }
//    outfile.flush();
//    outfile.close();
    int ans = checkRecursive(counter, s.size(), 0, counter.size() - 1);

    cout << ans << endl;

}
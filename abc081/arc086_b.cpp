#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = 10e15;
const ll MINF = -10e10;
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;
typedef pair<int, int> P;

int main() {
    int n;
    cin >> n;


    vector<int> numbers(n);
    rep(i, n) {
        cin >> numbers[i];
    }

    cout << 2 * n << endl;

    vector<P> first(n);
    rep(i, n) {
        P p(numbers[i], i);
        first[i] = p;
    }
    sort(first.begin(), first.end());
    rep(i, n) {
        cout << (first[i].second + 1) << ' ' << (i + 1) << endl;
        numbers[i] += first[i].first;
    }


    vector<P> second(n);
    rep(i, n) {
        P p(numbers[i], i);
        second[i] = p;
    }
    sort(second.begin(), second.end());
    rep(i, n) {
        cout << (second[i].second + 1) << ' ' << (i + 1) << endl;
        numbers[i] += second[i].first;
    }

    cout << endl;

//    rep(i, n) {
//        cout << numbers[i] << endl;
//    }


}
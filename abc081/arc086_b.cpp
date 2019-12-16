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
    int p_max = 0;
    int p_max_index = 0;
    int m_min = 0;
    int m_min_index = 0;
    rep(i, n) {
        int a;
        cin >> a;
        numbers[i] = a;
        if (a > 0) {
            if (a > p_max) {
                p_max = a;
                p_max_index = i;
            }
        } else {
            if (a < m_min) {
                m_min = a;
                m_min_index = i;
            }
        }
    }

    if (m_min + p_max < 0) {
        throw std::runtime_error("not implemented");
    }

    vector<P> ans;

    for (int i = 0; i < n; i++) {
        if (numbers[i] < 0) {
            ans.push_back(P(p_max_index, i));
            numbers[i] += p_max;
        }
    }


    for (int i = 1; i < n; i++) {
        if (numbers[i - 1] > numbers[i]) {
            ans.push_back(P(i - 1, i));
            numbers[i] += numbers[i - 1];
        }
    }

//    rep(i, n) {
//        cout << numbers[i] << endl;
//    }

    cout << endl;

    cout << ans.size() << endl;

    for (auto p : ans) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }

}
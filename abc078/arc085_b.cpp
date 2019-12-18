#include <bits/stdc++.h>
#include <cmath>

using namespace std;
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
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

vector<int> numbers;


int yGame(int x, int y, int start);

int xGame(int x, int y, int start) {
    int last = abs(numbers[numbers.size() - 1] - y);
    int last2 = abs(numbers[numbers.size() - 2] - numbers[numbers.size() - 1]);

    if (numbers.size() - start == 3) {
        return max(last, last2);
    }

    int y_game = yGame(start + 1, numbers[start], start + 1);

    return max(max(last, last2), y_game);
}

int yGame(int x, int y, int start) {
    int last = abs(numbers[numbers.size() - 1] - x);
    int last2 = abs(numbers[numbers.size() - 2] - numbers[numbers.size() - 1]);

    if (numbers.size() - start == 3) {
        return min(last, last2);
    }

    int x_game = xGame(x, numbers[start], start + 1);
    return min(min(last, last2), x_game);

}

int main() {

    int n, z, w;
    cin >> n >> z >> w;

    if (n == 1) {
        int a;
        cin >> a;
        cout << abs(a - w) << endl;
        return 0;
    }

    numbers.resize(n);
    rep(i, n) {
        cin >> numbers[i];
    }

    int ans = xGame(z, w, 0);
    cout << ans << endl;
}
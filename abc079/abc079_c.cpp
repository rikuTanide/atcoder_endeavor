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

struct N {
    int index, number;
    char operation;
};


int main() {
    char a;
    cin >> a;

    a -= '0';

    vector<N> nums(3);
    rep(i, 3) {
        char b;
        cin >> b;
        b -= '0';
        nums[i] = {i, b, ' '};
    }
    sort(nums.begin(), nums.end(), [](N n, N m) {
        return n.number > m.number;
    });

    int now = -7 + a;

    rep(i, 3) {
        if (now > 0) {
            nums[i].operation = '-';
            now -= nums[i].number;
        } else {
            nums[i].operation = '+';
            now += nums[i].number;

        }
    }
    sort(nums.begin(), nums.end(), [](N n, N m) {
        return n.index < m.index;
    });


    cout << (int) a;

    rep(i, 3) {
        cout << nums[i].operation << nums[i].number;
    }
    cout << "=7";

}
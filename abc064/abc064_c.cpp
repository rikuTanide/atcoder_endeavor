#include <bits/stdc++.h>
#include <cmath>

#include <assert.h>    // LON
#include <math.h>    // sqrt()


using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
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

const string
        gray = "gray",
        brown = "brown",
        green = "green",
        light_blue = "light_blue",
        blue = "blue",
        yellow = "yellow",
        orange = "orange",
        red = "red";

bool between(int a, int mi, int ma) {
    return mi <= a && a <= ma;
}

int main() {

    int over_count = 0;

    int n;
    cin >> n;

    set<string> colors;

    rep(i, n) {

        int a;
        cin >> a;

        if (between(a, 1, 399)) {
            colors.insert(gray);
        } else if (between(a, 400, 799)) {
            colors.insert(brown);
        } else if (between(a, 800, 1199)) {
            colors.insert(green);
        } else if (between(a, 1200, 1599)) {
            colors.insert(light_blue);
        } else if (between(a, 1600, 1999)) {
            colors.insert(blue);
        } else if (between(a, 2000, 2399)) {
            colors.insert(yellow);
        } else if (between(a, 2400, 2799)) {
            colors.insert(orange);
        } else if (between(a, 2800, 3199)) {
            colors.insert(red);
        } else {
            over_count++;
        }

    }

    int current_size = colors.size();

    {
        // min
        cout <<  current_size << ' ';
    }
    {
        // max
        cout << min(8, current_size + over_count) << endl;
    }


}
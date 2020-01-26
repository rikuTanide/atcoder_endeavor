#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define sz(x) ll(x.size())
//typedef pair<ll, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX / 100;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<char> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

string get_dir(double degd) {


    if (168.75 <= degd && degd < 191.25)return "S";
    if (11.25 <= degd && degd < 33.75)return "NNE";
    if (191.25 <= degd && degd < 213.75)return "SSW";
    if (33.75 <= degd && degd < 56.25)return "NE";
    if (213.75 <= degd && degd < 236.25)return "SW";
    if (56.25 <= degd && degd < 78.75)return "ENE";
    if (236.25 <= degd && degd < 258.75)return "WSW";
    if (78.75 <= degd && degd < 101.25)return "E";
    if (258.75 <= degd && degd < 281.25)return "W";
    if (101.25 <= degd && degd < 123.75)return "ESE";
    if (281.25 <= degd && degd < 303.75)return "WNW";
    if (123.75 <= degd && degd < 146.25)return "SE";
    if (303.75 <= degd && degd < 326.25)return "NW";
    if (146.25 <= degd && degd < 168.75)return "SSE";
    if (326.25 <= degd && degd < 348.75)return "NNW";
    return "N";

}

int get_w(int dis) {
    if (00 <= dis && dis <= 02) { return 0; }
    if (03 <= dis && dis <= 15) { return 1; }
    if (16 <= dis && dis <= 33) { return 2; }
    if (34 <= dis && dis <= 54) { return 3; }
    if (55 <= dis && dis <= 79) { return 4; }
    if (80 <= dis && dis <= 107) { return 5; }
    if (108 - 1 <= dis && dis <= 138) { return 6; }
    if (139 <= dis && dis <= 171) { return 7; }
    if (172 <= dis && dis <= 207) { return 8; }
    if (208 <= dis && dis <= 244) { return 9; }
    if (245 <= dis && dis <= 284) { return 10; }
    if (285 <= dis && dis <= 326) { return 11; }
    if (327 <= dis) { return 12; }

}

int main() {

    double deg;
    int dis;
    cin >> deg >> dis;
    deg /= 10;
    dis = (double) dis / (double) 6 + 0.5;

    int w = get_w(dis);
    if (w == 0) {
        cout << "C 0" << endl;
        return 0;
    }

    string dir = get_dir(deg);
    printf("%s %d\n", dir.c_str(), w);
}

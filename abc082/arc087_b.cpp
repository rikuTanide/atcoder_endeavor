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
typedef pair<int, char> P;


int main() {
    string s;
    cin >> s;

    int x, y;
    cin >> x >> y;

    auto it = s.find('T');
    if (it == string::npos) {
        if (s.size() == x && y == 0) {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    {
        s = s.substr(it);
        x -= it;
    }

    cout << endl;


    vector<int> horizontal;
    vector<int> vertical;
    {
        char direction = 'H';
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'T') {
                if (direction == 'H') {
                    direction = 'V';
                    horizontal.push_back(count);
                    count = 0;
                } else {
                    direction = 'H';
                    vertical.push_back(count);
                    count = 0;
                }
            } else {
                count++;
            }
        }
        if (direction == 'H') {
            horizontal.push_back(count);
        } else {
            vertical.push_back(count);
        }
    }

    sort(vertical.rbegin(), vertical.rend());
    sort(horizontal.rbegin(), horizontal.rend());

    for (int h : horizontal) {
        if (x > 0) {
            x -= h;
        } else {
            x += h;
        }
    }

    for (int v : vertical) {
        if (y > 0) {
            y -= v;
        } else {
            y += v;
        }
    }

    if (x == 0 && y == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
//#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
//typedef long long ll;
typedef long long ll;
//typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e15;
const ll MINF = -10e10;
//const int INF = INT_MAX / 100;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

//typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;
const double PI = 3.14159265358979323846;

typedef pair<ll, ll> P;

void print_line(vector<vector<int>> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        for (int y = 0; y < ans[i].size(); y++) {
            cout << ans[i][y];
        }
        cout << endl;
    }
}

int main() {

    int h, w;
    cin >> h >> w;


    if (h == 3 && w == 3) {
        cout << "Yes" << endl;
        printf("225\n");
        printf("555\n");
        printf("522\n");
        return 0;
    }


    if (h > 2 && w > 2) {
        cout << "No" << endl;
        return 0;
    }


    if (h == 1) {
        {
            // ２５２５...
            vector<vector<int>> ans;
            ans.push_back(vector<int>());
            int is2 = true;
            while (ans[0].size() < w) {
                if (is2) {
                    ans[0].push_back(2);
                    ans[0].push_back(2);
                } else {
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                }
                is2 = !is2;
            }
            if (ans[0].size() == w) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
        {
            // ５２５２...
            vector<vector<int>> ans;
            ans.push_back(vector<int>());
            int is2 = false;
            while (ans[0].size() < w) {
                if (is2) {
                    ans[0].push_back(2);
                    ans[0].push_back(2);
                } else {
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                }
                is2 = !is2;
            }
            if (ans[0].size() == w) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
    }


    if (w == 1) {
        {
            // ２５２５...
            vector<vector<int>> ans;
            int is2 = true;
            while (ans.size() < h) {
                if (is2) {
                    ans.push_back({2});
                    ans.push_back({2});
                } else {
                    ans.push_back({5});
                    ans.push_back({5});
                    ans.push_back({5});
                    ans.push_back({5});
                    ans.push_back({5});
                }
                is2 = !is2;
            }
            if (ans.size() == h) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
        {
            // ５２５２...
            vector<vector<int>> ans;
            int is2 = false;
            while (ans.size() < h) {
                if (is2) {
                    ans.push_back({2});
                    ans.push_back({2});
                } else {
                    ans.push_back({5});
                    ans.push_back({5});
                    ans.push_back({5});
                    ans.push_back({5});
                    ans.push_back({5});
                }
                is2 = !is2;
            }
            if (ans.size() == h) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
    }

    if (h == 2) {
        {
            vector<vector<int>> ans(2);
            bool is2 = true;
            while (ans[0].size() < w) {
                if (is2) {
                    ans[0].push_back(2);
                    ans[1].push_back(2);
                } else {
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(2);
                    ans[0].push_back(5);
                    ans[0].push_back(5);

                    ans[1].push_back(5);
                    ans[1].push_back(5);
                    ans[1].push_back(2);
                    ans[1].push_back(5);
                    ans[1].push_back(5);
                    ans[1].push_back(5);
                }
                is2 = !is2;
            }
            if (ans[0].size() == w) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
        {
            vector<vector<int>> ans(2);
            bool is2 = false;
            while (ans[0].size() < w) {
                if (is2) {
                    ans[0].push_back(2);
                    ans[1].push_back(2);
                } else {
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(5);
                    ans[0].push_back(2);
                    ans[0].push_back(5);
                    ans[0].push_back(5);

                    ans[1].push_back(5);
                    ans[1].push_back(5);
                    ans[1].push_back(2);
                    ans[1].push_back(5);
                    ans[1].push_back(5);
                    ans[1].push_back(5);
                }
                is2 = !is2;
            }
            if (ans[0].size() == w) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
    }

    if (w == 2) {
        {
            vector<vector<int>> ans;
            bool is2 = true;
            while (ans.size() < h) {
                if (is2) {
                    ans.push_back({2, 2});
                } else {
                    ans.push_back({5, 5});
                    ans.push_back({5, 5});
                    ans.push_back({2, 5});
                    ans.push_back({5, 2});
                    ans.push_back({5, 5});
                    ans.push_back({5, 5});

                }
                is2 = !is2;
            }
            if (ans.size() == h) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
        {
            vector<vector<int>> ans;
            bool is2 = false;
            while (ans.size() < h) {
                if (is2) {
                    ans.push_back({2, 2});
                } else {
                    ans.push_back({5, 5});
                    ans.push_back({5, 5});
                    ans.push_back({2, 5});
                    ans.push_back({5, 2});
                    ans.push_back({5, 5});
                    ans.push_back({5, 5});

                }
                is2 = !is2;
            }
            if (ans.size() == h) {
                cout << "Yes" << endl;
                print_line(ans);
                return 0;
            }
        }
    }


    cout << "No" << endl;

}
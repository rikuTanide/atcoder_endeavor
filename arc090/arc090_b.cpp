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
const int INF = INT_MAX;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)


//ifstream myfile("~/Downloads/02.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P>> PQ_ASK;
const int mod = 1000000007;

class UnionFind {
public:
    // 親の番号を格納する。親だった場合-size
    vector<int> parents;
    vector<int> distance;

    UnionFind(int n) {
        parents = vector<int>(n, -1);
        distance = vector<int>(n, 0);
    }

    // aがどのグループに属しているか
    int root(int a) {
        if (parents[a] < 0) {
            return a;
        }

        int a_parent = parents[a];
        int a_ancestor = root(parents[a]);
        if (a_parent == a_ancestor) {
            return a_ancestor;
        }
        int a_distance = distance[a];
        int a_parent_distance = distance[a_parent];
        distance[a] = a_distance + a_parent_distance;

        parents[a] = a_ancestor;
        return a_ancestor;
    }

    int size(int a) {
        return -parents[root(a)];
    }

    // aとbをくっつける
    bool connect(int a, int b, int d) {
        int ra = root(a);
        int rb = root(b);



        if (ra == rb) {
            int distance_a = distance[a];
            int distance_b = distance[b];
            int all_distance =  distance_a - distance_b;
            if (all_distance != d) {
                cout << "No" << endl;
                exit(0);
            }
            return false;
        }

        // 大きいほうにA
        if (size(ra) < size(rb)) {
            swap(ra, rb);
            swap(a, b);
        } else {
            d *= -1;
        }

        parents[ra] += parents[rb];
        parents[rb] = ra;
        distance[rb] = (distance[a] - distance[b]) + d;
        return true;
    }

};


int main() {

//    ifstream myfile("/home/riku/Downloads/02.txt");


    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    rep(i, m) {
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        r--;

        uf.connect(l, r, d);
    }

    cout << "Yes" << endl;

}
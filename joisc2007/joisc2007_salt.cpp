#include "grader.h"
#include "salt.h"


#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 1e18;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

bool check_drop_edge(int n, vector<P> &edges, vector<bool> edge_enable, vector<bool> vertex_enable, int target) {
    if (!edge_enable[target]) return false;
    edge_enable[target] = false;
    int ec = 0, vc = 0;
    rep(i, n - 1) if (edge_enable[i]) ec++;
    rep(i, n) if (vertex_enable[i]) vc++;

    return ec % 2 == 0 && vc % 2 == 0;
}

void drop_edge(int n, vector<P> &edges, vector<bool> &edge_enable, vector<bool> &vertex_enable, int target) {
    edge_enable[target] = false;
}

bool check_drop_vertex(int n, vector<P> &edges, vector<bool> edge_enable, vector<bool> vertex_enable, int target) {
    if (!vertex_enable[target]) return false;
    vertex_enable[target] = false;

    rep(i, n - 1) if (edges[i].first == target || edges[i].second == target) edge_enable[i] = false;

    int ec = 0, vc = 0;
    rep(i, n - 1) if (edge_enable[i]) ec++;
    rep(i, n) if (vertex_enable[i]) vc++;

    return ec % 2 == 0 && vc % 2 == 0;
}

void drop_vertex(int n, vector<P> &edges, vector<bool> &edge_enable, vector<bool> &vertex_enable, int target) {
    vertex_enable[target] = false;
    rep(i, n - 1) if (edges[i].first == target || edges[i].second == target) edge_enable[i] = false;
}


void drop(int n, vector<P> &edges, vector<bool> &edge_enable, vector<bool> &vertex_enable, int ru, int rv) {
    ru--;
    rv--;

    if (ru == rv) {
        drop_vertex(n, edges, edge_enable, vertex_enable, ru);
    } else {
        rep(i, n - 1) {
            if (edges[i].first == ru && edges[i].second == rv) {
                drop_edge(n, edges, edge_enable, vertex_enable, i);
            }
        }
    }
}


void play(int N, int E[][2]) {

    vector<P> edges(N);

    rep(i, N - 1) {
        edges[i].first = E[i][0];
        edges[i].second = E[i][1];

        edges[i].first--;
        edges[i].second--;
    }

    vector<bool> edge_enable(N - 1, true);
    vector<bool> vertex_enable(N, true);


    while (true) {

        rep(i, N - 1) {
            if (check_drop_edge(N, edges, edge_enable, vertex_enable, i)) {
                drop_edge(N, edges, edge_enable, vertex_enable, i);
                int ru, rv;
                turn(edges[i].first + 1, edges[i].second + 1, &ru, &rv);

                if (ru == 0 && rv == 0) {
                    return;
                }

                drop(N, edges, edge_enable, vertex_enable, ru, rv);
            }
        }


        rep(i, N) {
            if (check_drop_vertex(N, edges, edge_enable, vertex_enable, i)) {
                drop_vertex(N, edges, edge_enable, vertex_enable, i);
                int ru, rv;
                turn(i + 1, i + 1, &ru, &rv);

                if (ru == 0 && rv == 0) {
                    return;
                }

                drop(N, edges, edge_enable, vertex_enable, ru, rv);
            }
        }

    }
}

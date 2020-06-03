#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

double equal(double a, double b) {
    return fabs(a - b) < DBL_EPSILON;
}

std::istream &operator>>(std::istream &in, set<int> &o) {
    int a;
    in >> a;
    o.insert(a);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
//const ll mod = 1e10;

typedef priority_queue<ll, vector<ll>, greater<ll> > PQ_ASK;

template<typename T>
using matrix = std::vector<std::vector<T>>;

template<typename T>
matrix<T> make_matrix(int n, int m, T id = 0) {
    return matrix<T>(n, std::vector<T>(m, id));
}

template<typename T>
matrix<T> operator-(matrix<T> m) {
    for(int i=0; i<m.size(); ++i) {
        for(int j=0; j<m[i].size(); ++j) {
            m[i][j] = -m[i][j];
        }
    }
    return m;
}

template<typename T>
matrix<T> operator+(matrix<T> lhs, matrix<T> const& rhs) {
    assert(lhs.size() == rhs.size() && lhs[0].size() == rhs[0].size());
    for(int i=0; i<lhs.size(); ++i) {
        for(int j=0; j<lhs[i].size(); ++j) {
            lhs[i][j] += rhs[i][j];
        }
    }
    return lhs;
}

template<typename T>
matrix<T> operator-(matrix<T> lhs, matrix<T> const& rhs) {
    assert(lhs.size() == rhs.size() && lhs[0].size() == rhs[0].size());
    for(int i=0; i<lhs.size(); ++i) {
        for(int j=0; j<lhs[i].size(); ++j) {
            lhs[i][j] -= rhs[i][j];
        }
    }
    return lhs;
}

template<typename T>
matrix<T> operator*(T lhs, matrix<T> const& rhs) {
    auto res = rhs;
    for(int i=0; i<res.size(); ++i) {
        for(int j=0; j<res[i].size(); ++j) {
            res[i][j] *= lhs;
        }
    }
    return res;
}

template<typename T>
matrix<T> operator*(matrix<T> a, std::vector<T> const& b) {
    const int n = a.size();
    const int m = b.size();
    std::vector<T> res(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            res[i] += a[i][j] * b[j];
        }
    }
    return res;
}

template<typename T>
matrix<T> operator*(matrix<T> const& lhs, matrix<T> const& rhs) {
    if(lhs.size() == 1 && lhs[0].size() == 1) {
        return lhs[0][0] * rhs;
    }
    if(rhs.size() == 1 && rhs[0].size() == 1) {
        return rhs[0][0] * lhs;
    }
    assert(lhs[0].size() == rhs.size());
    matrix<T> res(lhs.size(), std::vector<T>(rhs[0].size()));
    for(int i=0; i<(int)lhs.size(); ++i) {
        for(int k=0; k<(int)rhs.size(); ++k) {
            for(int j=0; j<(int)rhs[0].size(); ++j) {
                res[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return res;
}

template <typename T>
matrix<T> modmul(matrix<T> const& lhs, matrix<T> const& rhs, long long const M) {
    matrix<T> res(lhs.size(), std::vector<T>(rhs[0].size()));
    for(int i = 0; i < (int)lhs.size(); ++i) {
        for(int k = 0; k < (int)rhs.size(); ++k) {
            for(int j = 0; j < (int)rhs[0].size(); ++j) {
                res[i][j] += lhs[i][k] * rhs[k][j] % M;
                res[i][j] %= M;
            }
        }
    }
    return res;
}

template <typename T>
std::vector<T> modmul(matrix<T> const& a, std::vector<T> const& b, long long const M) {
    const int n = a.size();
    const int m = b.size();
    std::vector<T> res(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            res[i] = res[i] + (a[i][j] * b[j]) % M;
            res[i] %= M;
        }
    }
    return res;
}

template <typename T>
matrix<T> transpose(matrix<T> const& m) {
    const int R = m.size(), C = m[0].size();
    matrix<T> res(C, std::vector<T>(R));
    for(int i=0; i<C; ++i) {
        for(int j=0; j<R; ++j) {
            res[i][j] = m[j][i];
        }
    }
    return res;
}

template<typename T>
matrix<T> eye(int n) {
    matrix<T> res(n, std::vector<T>(n));
    for(int i = 0; i < n; ++i) {
        res[i][i] = 1;
    }
    return res;
}

template <typename T>
matrix<T> modpow(matrix<T> x, long long n, long long M) {
    auto res = eye<T>(x.size());
    while(n > 0) {
        if(n & 1) {
            res = modmul(res, x, M);
        }
        x = modmul(x, x, M);
        n >>= 1;
    }
    return res;
}

template<typename T>
void print(matrix<T> const& m) {
    for(int i=0; i<m.size(); ++i) {
        for(int j=0; j<m[i].size(); ++j) {
            if(j != 0) {
                cout << ' ';
            }
            cout << (T)m[i][j];
        }
        cout << endl;
    }
}

using ll = long long;


ll modpow(ll x, ll n, ll M) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) {
            res = (res * x) % M;
        }
        x = (x * x) % M;
        n >>= 1;
    }
    return res;
}


int main() {
    ll A, B, M;
    cin >> A >> B >> M;

    ll g = __gcd(A, B);
    vector<ll> b1 = {11, 1};
    vector<ll> b2(2);
    b2[0] = modpow(10, g, M) + 1;
    b2[1] = 1;
    auto C = make_matrix<ll>(2, 2);
    C[0][0] = 11;
    C[0][1] = -10 + M;
    C[1][0] = 1;
    C = modpow(C, A - 1, M);
    auto C2 = make_matrix<ll>(2, 2);
    C2[0][0] = modpow(10, g, M) + 1;
    C2[0][1] = -modpow(10, g, M) + M;
    C2[1][0] = 1;
    C2 = modpow(C2, B / g - 1, M);

    ll x = modmul(C, b1, M)[1];
    ll y = modmul(C2, b2, M)[1];
    cout << (x * y) % M << endl;


}


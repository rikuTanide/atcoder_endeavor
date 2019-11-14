#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)


struct RollingHash {
    vector<int> mod = {(int) (1e9 + 7), (int) (1e9 + 9), 1234567891};
    vector<int> k = {1007, 1009, 1013};
    string s;
    vector<vector<ll>> hash;
    vector<vector<ll>> powTable;

    RollingHash(string s) {
        this->s = s;
        this->hash = vector<vector<ll>>(mod.size(), vector<ll>(s.size() + 1));

        for (int i = 0; i < mod.size(); i++) {
            for (int j = s.size() - 1; j >= 0; j--) {
                hash[i][j] = hash[i][j + 1] * this->k[i];
                hash[i][j] += s[j];
                hash[i][j] %= mod[i];
            }
        }
        powTable = vector<vector<ll>>(mod.size(), vector<ll>(s.size() + 1));// new long[mod.Length, S.Length + 1];

        for (int i = 0; i < mod.size(); i++) {
            powTable[i][0] = 1;
            for (int j = 1; j < s.size() + 1; j++) {
                powTable[i][j] = (powTable[i][j - 1] * k[i]) % mod[i];
            }
        }

    }

    ll getHash(int t, int start, int end) {
        ll r = hash[t][start] - hash[t][end] * powTable[t][end - start];
        r %= mod[t];
        if (r < 0) r += mod[t];
        return r;
    }

    bool isSame(int Astart, int Bstart, int Aend, int Bend) {
        int len = Aend - Astart;
        if (len != Bend - Bstart) return false;
        for (int i = 0; i < mod.size(); i++) {
            if (getHash(i, Astart, Aend) != getHash(i, Bstart, Bend)) return false;
        }
        return true;
    }

    bool isSame(int Astart, int Bstart, int Aend, int Bend, RollingHash *rh) {
        if (rh == nullptr) return isSame(Astart, Bstart, Aend, Bend);
        int len = Aend - Astart;
        if (len != Bend - Bstart) return false;
        for (int i = 0; i < mod.size(); i++) {
            if (getHash(i, Astart, Aend) != rh->getHash(i, Bstart, Bend)) return false;
        }
        return true;
    }

};


vector<int> uni;

void init(int N) {
    uni = vector<int>(N);
    for (int i = 0; i < N; i++) {
        uni[i] = -1;
    }
}

int root(int a) {
    if (uni[a] < 0) return a;
    else return uni[a] = root(uni[a]);
}

bool connect(int a, int b) {
    a = root(a);
    b = root(b);
    if (a == b) return false;
    if (uni[a] > uni[b]) swap(a, b);
    uni[a] += uni[b];
    uni[b] = a;
    return true;
}


int main() {
    string s;
    cin >> s;
    int n = s.size();

    string t;
    cin >> t;

    string sb;
    sb.append(s);
    sb.append(s);
    sb.append(s);
    while (t.size() * 2 > sb.size()) sb.append(s);

    string ts = t + sb;
    RollingHash rh(ts);

    vector<bool> ok(n);
    for (int i = 0; i < n; i++) {
        //okに、「S[i]から文字列Tがあるか」を入れる
        //これだと遅い
        //if (S.IndexOf(T, i) == i) ok[i] = true;
        if (rh.isSame(0, t.size() + i, t.size(), t.size() * 2 + i)) {
            ok[i] = true;
        }
    }

    init(n);
    for (int i = 0; i < n; i++) {
        if (ok[i] && ok[(i + t.size()) % n]) {
            if (!connect(i, (i + t.size()) % n)) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (ok[i]) {
            int r = root(i);
            ans = max(ans, -uni[r]);
        }
    }

    cout << ans << endl;
}


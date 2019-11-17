#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 1001001001;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1e9 + 7;
string s;


bool isYYMM() {
    string b;
    b = b + s[2];
    b = b + s[3];
    int num = std::atoi(b.c_str());

    if(num > 12 || num == 0) {
        return false;
    }
    return true;
}

bool isMMYY() {
    string b;
    b = b + s[0];
    b = b + s[1];
    int num = std::atoi(b.c_str());
    if(num > 12 || num == 0) {
        return false;
    }
    return true;
}

int main() {
    cin >> s;

    if(isYYMM() && isMMYY()) {
        cout << "AMBIGUOUS" << endl;
        return 0;
    }

    if(isYYMM()) {
        cout << "YYMM" << endl;
        return 0;
    }

    if( isMMYY()) {
        cout << "MMYY" << endl;
        return 0;
    }

    cout << "NA" << endl;


}


#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//#define rep(i, n) for (ll i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<ll, ll> P;
const ll INF = 10e17;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)
#define ret() return 0;

std::istream &operator>>(std::istream &in, set<int> &o) {
    ll a;
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
const int mod = 1000000007;

long long int garchomp_TL[1000100], damage_TL[1000100], combo_TL[1000100];

int main() {

    string s;
    cin >> s;
    s += "----------";

    for ( long long int i = 0; i < 1000100; i++ ) {
        garchomp_TL[i] = 0;
        damage_TL[i] = 0;
        combo_TL[i] = 0;
    }

    long long int garchomp = 5;
    long long int combo = 0;
    long long int ans = 0;
    long long int tame = 0;

    for ( long long int i = 0; i < s.size(); i++ ) {
        if ( tame > 0 ) {
            tame--;
        }else if ( s[i] == '-' ) {
        }else if ( s[i] == 'N' ) {
            if ( garchomp > 0 ) {
                garchomp--;
                garchomp_TL[ i + 6 ]++;
                damage_TL[ i+1 ] += 10 + combo / 10;
                combo_TL[ i+1 ]++;
            }
        }else {
            if ( garchomp > 2 ) {
                garchomp -= 3;
                garchomp_TL[ i + 8 ] += 3;
                damage_TL[ i+3 ] += 50 + combo / 10 * 5;
                combo_TL[ i+3 ]++;
                tame += 2;
            }
        }
        garchomp += garchomp_TL[i];
        ans += damage_TL[i];
        combo += combo_TL[i];
    }

    cout << ans << endl;

    return 0;



}


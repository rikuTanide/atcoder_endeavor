#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
//typedef pair<ll, ll> P;
typedef pair<int, int> P;
const ll INF = 1e15;
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

//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);
const int mod = 1000000007;
//const ll mod = 1e10;
typedef priority_queue<string, vector<string>, greater<string> > PQ_ASK;

class Keta {
    vector<int> digits;

public:
    Keta(ll i) : digits(i == 0 ? 1 : log10(i) + 1) {
        for (int k = 0; k < digits.size(); k++) {
            digits[k] = i % 10;
            i /= 10;
        }
        reverse(digits.begin(), digits.end());
    }

    int keta() {
        return digits.size();
    }

    int get(int index) {
        assert(index < keta());
        return digits[index];
    }

    void set(int index, int value) {
        assert(index < keta());
        digits[index] = value;
    }

    ll to_value() {
        ll ans = 0;
        for (int i = 0; i < keta(); i++) {
            ans += digits[i];
            ans *= 10;
        }
        ans /= 10;
        return ans;
    }

};


int main() {
    vector<int> convert(10), revert(10);

    rep(i, 10) {
        int b;
        cin >> b;
        revert[i] = b;
        convert[b] = i;
    }

    int n;
    cin >> n;

    vector<ll> numbers(n);

    rep(i, n) {
        ll a;
        cin >> a;
        Keta keta(a);
        for (int j = 0; j < keta.keta(); j++) {
            keta.set(j, convert[keta.get(j)]);
        }
        numbers[i] = keta.to_value();
    }

    sort(numbers.begin(), numbers.end());

    rep(i, n) {
        ll a = numbers[i];
        Keta keta(a);
        for (int j = 0; j < keta.keta(); j++) {
            keta.set(j, revert[keta.get(j)]);
        }
        cout << keta.to_value() << endl;
    }


}

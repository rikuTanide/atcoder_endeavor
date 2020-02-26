#include <bits/stdc++.h>
#include <cmath>

const double PI = 3.14159265358979323846;
//using namespace boost::multiprecision;
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef pair<ll, ll> P;
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
typedef priority_queue<long long, vector<long long>, greater<long long> > PQ_ASK;


bool is_natural(int d, string a, string b) {
    if (d % 2 == 0) {
        if (a == b) return false;
    } else {
        if (a != b) return false;
    }
    return true;
}

string check(vector<string> &seats, int ceil, int floor, int mid, string v) {

    string c = seats[ceil],
            f = seats[floor],
            m = seats[mid];

    assert(c != "");
    assert(f != "");
    assert(m != "");

    int mf = mid - floor - 1;
    bool b1 = is_natural(mf, m, f);
    int cm = ceil - mid - 1;
    bool b2 = is_natural(cm, c, m);
    assert(b1 xor b2);

    if (b1) {
        return "second";
    } else {
        return "first";
    }
}

int main() {

    int n;
    cin >> n;

    vector<string> seats(n, "");

    {
        cout << 0 << endl << flush;
        string v;
        cin >> v;
        if (v == "Vacant") {
            ret();
        }
        seats[0] = v;

        cout << n - 1 << endl << flush;
        cin >> v;
        if (v == "Vacant") {
            ret();
        }
        seats[n - 1] = v;
    }

    int floor = 0, ceil = n - 1;

    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        cout << mid << endl << flush;

        string v;
        cin >> v;
        if (v == "Vacant") {
            ret();
        }

        seats[mid] = v;

        string s = check(seats, ceil, floor, mid, v);
        if (s == "second") {
            floor = mid;
        } else {
            ceil = mid;
        }
    }

    __throw_runtime_error("okasii");


}

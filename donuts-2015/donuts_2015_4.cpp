#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//namespace mp = boost::multiprecision;

using namespace std;

const double PI = 3.14159265358979323846;
typedef long long ll;
const long double EPS = 1e-9;

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

std::istream &operator>>(std::istream &in, set<char> &o) {
    string a;
    in >> a;
    for (char c : a) o.insert(c);
    return in;
}

std::istream &operator>>(std::istream &in, queue<int> &o) {
    ll a;
    in >> a;
    o.push(a);
    return in;
}

bool contain(set<char> &s, char a) { return s.find(a) != s.end(); }

//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;

class SetOrder {
    set<int> s;

public:
    void insert(int v) {
        s.insert(v);
    }

    int left(int v) {
        auto it = s.find(v);
        assert(it != s.end());
        if (it == s.begin()) return -1;
        it--;
        return *it;
    }

    int right(int v) {
        auto it = s.find(v);
        assert(it != s.end());
        it++;
        if (it == s.end()) return -1;
        return *it;
    }

    int erase(int v) {
        auto it = s.find(v);
        assert(it != s.end());
        s.erase(it);
    }

    vector<int> get_diff() {
        vector<int> ans;
        int prev = -1;
        for (int v : s) {
            if (prev == -1) {
                prev = v;
                continue;
            }
            ans.push_back(v - prev);
            prev = v;
        };
        return ans;
    }

};

struct MultisetGrouping {
    multiset<int> left, right;
    int l_size;
    int l_sum = 0;
public:
    MultisetGrouping(int l_size) : l_size(l_size) {}

    void initialize(vector<int> &v) {
        sort(v.begin(), v.end());
        rep(i, v.size()) {
            if (i < l_size) {
                l_sum += v[i];
                left.insert(v[i]);
            } else {
                right.insert(v[i]);
            }
        }
    }

    void insert(int v) {
        left.insert(v);
        l_sum += v;
        if (left.size() > l_size) {
            auto it = left.end();
            it--;
            int max_v = *it;
            left.erase(it);
            right.insert(max_v);
            l_sum -= max_v;
        }
    }

    void erase(int v) {
        {
            auto it = right.find(v);
            if (it != right.end()) {
                right.erase(it);
                return;
            }
        }
        auto it = left.find(v);
//        assert(it != left.end());
        left.erase(it);
        l_sum -= v;

        auto right_min = right.begin();
//        assert(right_min != right.end());

        int min_v = *right_min;
        right.erase(right_min);

        left.insert(min_v);
        l_sum += min_v;

    }

    void size_down() {
        auto it = left.end();
        it--;
        int max_v = *it;
        left.erase(it);
        right.insert(max_v);
        l_sum -= max_v;
        l_size--;

        assert(left.size() == l_size);

    }

    int get_l_sum() {
        return l_sum;
    }

};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> boxes(n);
    rep(i, n) cin >> boxes[i];

    SetOrder so;
    rep(i, n) so.insert(boxes[i]);

    vector<int> tmp_v = so.get_diff();

    MultisetGrouping mg(n - k);
    mg.initialize(tmp_v);

    cout << mg.get_l_sum() << endl;


    int q;
    cin >> q;

    rep(_, q) {

        int a;
        cin >> a;
        a--;

        int v = boxes[a];

        int l = so.left(v);
        int r = so.right(v);
        so.erase(v);

        if (l > -1) {
            mg.erase(v - l);
        }
        if (r > -1) {
            mg.erase(r - v);
        }
        if (l > -1 && r > -1) {
            mg.insert(r - l);
        }

        mg.size_down();
        cout << mg.get_l_sum() << endl;

    }


}

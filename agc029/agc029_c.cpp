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


void normalize(vector<P> &nums) {
    if (nums.size() > 1) {
        if (nums[nums.size() - 1].first == nums[nums.size() - 2].first) {
            nums[nums.size() - 2].second += nums[nums.size() - 1].second;
            nums.pop_back();
        }
    }
}

void zouka(vector<P> &nums) {
    if (nums.back().second == 1) {
        nums.back().first += 1;
    } else {
        nums.back().second--;
        nums.push_back(P(nums.back().first + 1, 1));
    }
    normalize(nums);
}

bool check(vector<int> &a, int mid) {
    int n = a.size();
    vector<P> nums;
    nums.emplace_back(0, a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < a[i]) nums.push_back(P(0, a[i] - a[i - 1]));
        else {
            long long sum = 0;
            while (nums.size() > 0 && sum + nums.back().second <= a[i - 1] - a[i]) {
                sum += nums.back().second;
                nums.pop_back();
            }
            nums.back().second -= a[i - 1] - a[i] - sum;

            if (nums.back().first == mid - 1) {
                if (nums.size() == 1) {
                    return false;
                }
                long long num = nums.back().second;
                nums.pop_back();
                zouka(nums);
                nums.push_back(P(0, num));
            } else zouka(nums);
        }
        normalize(nums);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int floor = 0, ceil = n + 1;
    while (floor + 1 < ceil) {
        int mid = (floor + ceil) / 2;
        bool ok = check(a, mid);
        if (ok) ceil = mid;
        else floor = mid;
    }
    cout << ceil << endl;
}

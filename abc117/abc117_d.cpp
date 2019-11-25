#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)

const int mod = 1000000007;
ll n, k;
vector<int> one_counts(50);
vector<ll> ans_zoukaryos(50);
vector<ll> a_list;

ll ans = 0;

void check(int keta, ll sample) {
    //0011101001101001010011101111100001110010
    // 端まで到達した
    auto s = static_cast<std::bitset<40>>(sample).to_string();
    // kが0でsampleも0 -> 桁を下げて再調査
    // kが0でsampleが1 -> 無理
    // kが1でsampleが0 -> それ以下の桁は最もいいものを選ぶ
    // kが1でsampleが1　-> 桁を下げて再調査

    if (keta < 0) {
        return;
    }

    int k_bit = (k >> keta) & 1;
    if (k_bit == 0) {
        check(keta - 1, sample);
    } else {
        {
            ll now = 0;
            for (int i = 0; i < 50; i++) {

                if (i < keta) {
                    ll zokaryo = ans_zoukaryos[i];
                    now += max(zokaryo, 0ll);
                }else if(i == keta) {

                    ll one_count = one_counts[i];
                    ll bairitsu = 1ll << i;
                    now += bairitsu * one_count;

                } else {
                    ll one_count = one_counts[i];

                    int sample_bit = (sample >> keta) & 1;
                    ll bairitsu = 1ll << i;

                    if (sample_bit == 0) {
                        now += bairitsu * one_count;
                    } else {
                        now += bairitsu * (n - one_count);
                    }

                }
                // sampleを含んでいない
            }
            ans = max(now, ans);
        }
        {
            ll next = sample + (1ll << keta);
            check(keta - 1, next);
        }
    }

}

int main() {
    cin >> n >> k;

    rep(i, n) {
        ll a;
        cin >> a;
        a_list.push_back(a);
    }

    for (ll a : a_list) {
        for (int keta = 0; keta < 50; keta++) {
            int konoketaha_one_ka = (a >> keta) & 1;
            one_counts[keta] += konoketaha_one_ka;
        }
    }


    rep(i, 50) {
        ll bairitsu = 1ll << i;
        ll one_count = one_counts[i];
        ll zero_count = n - one_count;
        ll one_zouraryo = zero_count - one_count;

        ans_zoukaryos[i] = bairitsu * max(one_count, zero_count);
    }

    ans = accumulate(a_list.begin(), a_list.end(), 0ll);

    check(50, 0);

    cout << ans << endl;

}


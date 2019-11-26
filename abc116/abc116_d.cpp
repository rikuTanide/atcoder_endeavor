#include <bits/stdc++.h>
#include <cmath>

using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef long long ll;
//typedef pair<int, int> P;
typedef pair<ll, ll> P;
//const double INF = 1e10;
const ll INF = 10e10;
const ll MINF = -10e10;
//const int INF = INT_MAX;
#define mins(x, y) x = min(x, y)
#define maxs(x, y) x = max(x, y)
typedef priority_queue<P, vector<P>, greater<P> > PQ_ASK;
const int mod = 1000000007;


int main() {
    ll n, k;
    cin >> n >> k;

    vector<P> all_neta(n);// <oishisa , shurui>

    rep(i, n) {
        ll t, d;
        cin >> t >> d;
        P p(d, t);
        all_neta[i] = p;
    }

    ll neta_count = 0;
    {

        set<ll> neta_set;
        for (auto a : all_neta) {
            neta_set.insert(a.second);
        }
        neta_count = neta_set.size();

        ll i = 0;
        map<ll, ll> neta_id_map;
        for (ll neta_id : neta_set) {
            neta_id_map[neta_id] = i;
            i++;
        }
        for (ll i = 0; i < n; i++) {
            all_neta[i].second = neta_id_map[all_neta[i].second];
        }

    }

    // 各ネタ最おいしソート
    vector<P> kakuneta_sai_oishi_sort = vector<P>(neta_count, P(0, 0));

    {

        for (auto a : all_neta) {
            ll neta = a.second;
            ll oishisa = a.first;

            if (kakuneta_sai_oishi_sort[neta].first < oishisa) {
                kakuneta_sai_oishi_sort[neta] = P(oishisa, neta);
            }

        }
    }

    sort(all_neta.rbegin(), all_neta.rend());
    sort(kakuneta_sai_oishi_sort.rbegin(), kakuneta_sai_oishi_sort.rend());

    vector<ll> neta_saiyou_count = vector<ll>(neta_count, 0);

    ll saiyo_su = 0;
    ll oishisa_sum = 0;

    for (ll i = 0; i < k; i++) {
        P p = all_neta[i];
        if (neta_saiyou_count[p.second] == 0) {
            saiyo_su++;
        }
        oishisa_sum += p.first;
        neta_saiyou_count[p.second]++;
    }

    ll ans = oishisa_sum + (saiyo_su * saiyo_su);

    vector<PQ_ASK> netagoto_senkouochi_queue(neta_count, PQ_ASK());

    for (ll i = 0; i < k; i++) {
        P p = all_neta[i];
        if (neta_saiyou_count[p.second] >= 2) {
            netagoto_senkouochi_queue[p.second].push(p);
        }
    }

    priority_queue<P> fukkatsu_list;
    for (ll i = 0; i < neta_count; i++) {
        P neta_daihyo = kakuneta_sai_oishi_sort[i];
        if (neta_saiyou_count[neta_daihyo.second] == 0) {
            fukkatsu_list.push(neta_daihyo);
        }
    }


    PQ_ASK daihyo_senkouochi_queue;
    for (ll i = 0; i < neta_count; i++) {
        if (!netagoto_senkouochi_queue[i].empty()) {
            P p = netagoto_senkouochi_queue[i].top();
            daihyo_senkouochi_queue.push(p);
            netagoto_senkouochi_queue[i].pop();
        }
    }


    while (!daihyo_senkouochi_queue.empty() && !fukkatsu_list.empty()) {
        P daihyo_ochi = daihyo_senkouochi_queue.top();
        daihyo_senkouochi_queue.pop();
        if (netagoto_senkouochi_queue[daihyo_ochi.second].size() > 1) {
            P next_staging = netagoto_senkouochi_queue[daihyo_ochi.second].top();
            daihyo_senkouochi_queue.push(next_staging);
        }
        P fukkatsu = fukkatsu_list.top();
        fukkatsu_list.pop();

        saiyo_su++;
        oishisa_sum -= daihyo_ochi.first;
        oishisa_sum += fukkatsu.first;

        ll now = oishisa_sum + (saiyo_su * saiyo_su);
        ans = max(now, ans);

    }

    cout << ans << endl;


}
#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;


int main() {

    ll product_count, voucher_count;
    cin >> product_count>> voucher_count;

    priority_queue<ll> prices;

    rep(i, product_count) {
        ll price;
        cin >> price;
        prices.push(price);
    }

    for(ll x = 0 ; x < voucher_count ; x ++) {
        auto price = prices.top();
        prices.pop();
        prices.push(price / 2);
    }

    ll sum = 0;
    while(!prices.empty()) {
        sum += prices.top();
        prices.pop();
    }

    cout << sum << endl;


}

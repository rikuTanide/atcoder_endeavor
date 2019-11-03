#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

const int INF = 1001001001;


int main() {

    int n;
    string str;
    cin >> n;
    cin >> str;

    int start = str.size() / 2;
    if (str.size() % 2 == 1) {
        start++;
    }

    // lは検索する文字の長さ
    for (int l = start; l >= 1; l--) {
        // 検索する文字を探す領域
        // 少なくとも末尾の l 文字までに見つけないと意味がない
        string source = str.substr(0, str.size() - l);
        for (int s = 0; s + l <= source.size(); s++) {
            string needle = str.substr(s, l);
            string area = str.substr(s + l);

            if (area.find(needle) != string::npos) {
                cout << l << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;


}

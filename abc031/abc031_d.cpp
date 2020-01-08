#include <bits/stdc++.h>
#include <cmath>

using namespace std;
typedef long long ll;
//typedef unsigned long long ll;

//#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) ll(x.size())
typedef pair<int, int> P;
//typedef pair<ll, ll> P;
//const double INF = 1e10;
//const ll INF = LONG_LONG_MAX;
//const ll INF = 1e15;
const ll MINF = LONG_LONG_MIN;
const int INF = INT_MAX / 10;
#define cmin(x, y) x = min(x, y)
#define cmax(x, y) x = max(x, y)

bool contain(set<int> &s, int a) { return s.find(a) != s.end(); }


//ifstream myfile("C:\\Users\\riku\\Downloads\\0_00.txt");
//ofstream outfile("log.txt");
//outfile << setw(6) << setfill('0') << prefecture << setw(6) << setfill('0') << rank << endl;
// std::cout << std::bitset<8>(9);

typedef priority_queue<ll, vector<ll>, greater<ll>> PQ_ASK;
const int mod = 1000000007;

bool string_match(string s, int char_index, string candidate) {
    if (s.size() < candidate.size() + char_index) {
        return false;
    }
    return s.substr(char_index, candidate.size()) == candidate;
}

string sub_string(string s, int char_index, int len) {
    if (char_index + len > s.size()) {
        return "";
    }
    string sub = s.substr(char_index, len);
    return sub;
}

bool recursive(vector<string> &numbers,
               vector<string> &words,
               vector<string> &terms,
               int word_index,
               int char_index,
               int number_index,
               int number_char_index) {
    if (number_index == numbers.size()) {
        return true;
    }
    if (number_char_index == numbers[number_index].size() && char_index == words[word_index].size()) {
        return recursive(numbers,
                         words,
                         terms,
                         word_index + 1,
                         0,
                         number_index + 1,
                         0);
    }
    if ((number_char_index == numbers[number_index].size() && char_index != words[word_index].size())
        || (number_char_index != numbers[number_index].size() && char_index == words[word_index].size())) {
        return false;
    }
    char n = numbers[number_index][number_char_index];
    int nn = n - '0';
    string candidate = terms[nn];
    if (!candidate.empty()) {
        if (string_match(words[word_index], char_index, candidate)) {
           return recursive(numbers,
                      words,
                      terms,
                      word_index,
                      char_index + candidate.size(),
                      number_index,
                      number_char_index + 1);
        } else {
            return false;
        }
    }
    rep(l, 3) {
        string next = sub_string(words[word_index], char_index, l + 1);
        if (next != "") {
            terms[nn] = next;
            bool b = recursive(numbers,
                               words,
                               terms,
                               word_index,
                               char_index + l + 1,
                               number_index,
                               number_char_index + 1);
            if (b) {
                return true;
            } else {
                terms[nn] = "";
            }
        }
    }

    return false;
}

int main() {
    int k, n;
    cin >> k >> n;
    vector<string> words(n);
    vector<string> numbers(n);
    rep(i, n) {
        cin >> numbers[i];
        cin >> words[i];
    }

    vector<string> terms(10, "");
    recursive(numbers, words, terms, 0, 0, 0, 0);

    for (int i = 1; i <= k; i++) {
        cout << terms[i] << endl;
    }
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> words(n);
    vector<pair<string, int>> dict;
    rep(i, n){
        string s;
        cin >> s;
        words[i] = s;

        string rs = "";
        rep(j, s.size()) rs += s[s.size()-j-1];

        dict.push_back(make_pair(rs, i));
    }

    sort(dict.begin(), dict.end());

    rep(i, n) cout << words[dict[i].second] << endl;

    return 0;
}
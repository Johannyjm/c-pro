#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> b(10);
    map<char, int> mp;
    rep(i, 10) {
        cin >> b[i];
        mp['0' + b[i]] = i;
    }

    int n;
    cin >> n;
    vector<pair<int, string>> res(n);
    rep(i, n){
        string s;
        cin >> s;
        int m = s.size();
        
        int val = 0;
        int base = 1;
        for(int j = m-1; j >= 0; --j){
            val += mp[s[j]] * base;
            base *= 10;
        }

        res[i] = make_pair(val, s);
    }

    sort(res.begin(), res.end());

    rep(i, n) cout << res[i].second << endl;

    return 0;
}
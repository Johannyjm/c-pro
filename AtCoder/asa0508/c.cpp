#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    map<string, int> mp;
    rep(i, n){
        string s;
        cin >> s;

        sort(s.begin(), s.end());
        ++mp[s];
    }
    
    ll res = 0;
    for(auto i = mp.begin(); i != mp.end(); ++i){
        ll v = i->second;
        res += v * (v-1) / 2;
    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();
    vector<int> ans(n+1, 0);

    rep(i, n){
        if(s[i] == '<') ans[i+1] = max(ans[i]+1, ans[i+1]);
    }

    for(int i = n-1; i >= 0; --i){
        if(s[i] == '>') ans[i] = max(ans[i+1]+1, ans[i]);
    }

    ll res = 0;
    rep(i, n+1) res += ans[i];

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size() + 1;

    vector<int> res1(n, 0);
    rep(i, n){
        if(s[i] == '<') res1[i+1] = 1;
    }
    rep1(i, n) res1[i] += res1[i-1];
    rep(i, n) cout << res1[i] << " ";
    cout << endl;

    vector<int> res2(n, 0);
    string s2 = s;
    reverse(s2.begin(), s2.end());
    rep(i, n){
        if(s2[i] == '>') res2[i+1] = 1;
    }
    rep1(i, n) res2[i] += res2[i-1];
    reverse(res2.begin(), res2.end());
    rep(i, n) cout << res2[i] << " ";
    cout << endl;

    int mn = 1001001001;
    rep(i, n){
        cout << res1[i] + res2[i] << " ";
        mn = min(mn, res1[i] + res2[i]);
    }
    cout << endl;

    ll res = 0;
    rep(i, n){
        res += res1[i] + res2[i] - mn;
        cout << res1[i] + res2[i] - mn << " ";
    }
    cout << endl;
    
    cout << res << endl;

    return 0;
}
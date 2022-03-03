#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    unordered_set<string> exps;
    rep(i, n) cin >> s[i];
    rep(i, m){
        cin >> t[i];
        exps.insert(t[i]);
    }

    for(string str: s){
        if(exps.count(str)) puts("Yes");
        else puts("No");
    }

    return 0;
}
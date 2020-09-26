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
    int n = s.size();
    
    ll res = 0;
    rep(i, n){
        if(s[i]=='U') res += n-(i+1) + 2*i;
        else res += 2*(n-(i+1)) + i;
    }

    cout << res << endl;

    return 0;
}
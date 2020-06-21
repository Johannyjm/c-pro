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

    vector<int> sm(n, 0);
    rep(i, n-1){
        if(s[i] == '2' && s[i+1] == '5'){
            sm[i] = 1;
            sm[i+1] = 1;
        }
    }
    sm.push_back(0);

    vector<int> grs;
    int cnt = 0;
    rep(i, n+1){
        if(sm[i] == 1){
            ++cnt;
        }
        else if(cnt != 0){
            grs.push_back(cnt);
            cnt = 0;
        }
    }

    ll res = 0;
    rep(i, grs.size()){
        ll gr = grs[i]/2;
        res += (1ll+gr) * gr / 2;
    }

    cout << res << endl;

    return 0;
}
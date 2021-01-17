#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    map<int, int> cnt;
    rep(i, n){
        cin >> a[i];
        ++cnt[a[i]];
    }

    ll res = 0;
    ll now = 0;
    while(1){
        if(cnt[now] == 0) break;
        k = min(k, cnt[now]);
        res += k;
        ++now;
    }
    
    cout << res << endl;


    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<int, int> cnt;
    rep(i, n){
        int a;
        cin >> a;
        ++cnt[a];
    }

    bool flg = true;
    rep1(i, n+1){
        if(cnt[i] != 1) flg = false;
    }

    if(flg) puts("Yes");
    else puts("No");

    return 0;
}
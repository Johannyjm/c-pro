#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    int mn_a = 1001001001;
    rep(i, n){
        cin >> a[i];
        mn_a = min(mn_a, a[i]);
    }

    if(n == 1){
        if(a[0]%2 == 1) puts("first");
        else puts("second");
        
        return 0;
    }

    int cnt = 0;
    rep(i, n){
        if(a[i] - mn_a) ++cnt;
    }

    if(cnt > 1) puts("second");
    else puts("first");


    return 0;
}
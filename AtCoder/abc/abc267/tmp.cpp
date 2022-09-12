#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;

    int ans;

    if(m>=x){
        ans = t;
    }

    else{
        ans = t-(d*(x-m));
    }

    cout << ans;

    return 0;
}
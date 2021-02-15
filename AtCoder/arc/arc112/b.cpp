#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll b, c;
    cin >> b >> c;

    ll cnt = 0;
    if(b < 0) ++cnt;
    cnt += abs(b);

    if((b>=0 && c <= 2*cnt) || (b<0 && c<=abs(b)*2-1)){
        if(c <= 1) cout << c+1 << endl;
        else cout << c*2 - 1 << endl;
        return 0;
    }

    ll res = c;
    if(cnt <= 1) res += cnt;
    else{
        if(b >= 0) res += 2*cnt-1;
        else res += 2*cnt-2;
    }

    cout << res << endl;



    return 0;
}
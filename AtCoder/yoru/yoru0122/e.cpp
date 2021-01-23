#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool check(ll t, ll a){
    if(t==0||a==0) return true;
    if(t<0 && a>0) return true;
    if(t>0 && a<0) return true;

    return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    if(t1*a1+t2*a2 == t1*b1+t2*a2){
        puts("infinity");
        return 0;
    }

    vector<ll> takahashi, aoki;
    takahashi.push_back(0);
    aoki.push_back(0);

    int res = 0;
    rep(i, 200000000){
        if(i%(t1+t2) < t1){
            takahashi.push_back(takahashi.back() + a1);
            aoki.push_back(aoki.back() + b1);
        }
        else{
            takahashi.push_back(takahashi.back() + a2);
            aoki.push_back(aoki.back() + b2);
        }

        if(check(takahashi[i]-aoki[i], takahashi[i+1]-aoki[i+1])){
            ++res;
        }
    }

    cout << res-1 << endl;

    return 0;
}
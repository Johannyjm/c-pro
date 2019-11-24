#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int calcD(ll num){
    int res = 0;
    while(num>0){
        num/=10;
        res++;
    }
    return res;
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = x / a;
    if(ans>0){
        if(ans>1000000000) ans = 1000000000;
        else{
            if(a*x+b*calcD(ans)<=x){
                ans = (x-b*calcD(ans))/a;
            }
            else{
                while(a>0){
                   if(a*ans+b*calcD(ans)<=x) break;
                   else {
                       a -= 1;
                       ll ans = x / a;
                   }
                   
                }
            }
        }
    }


    cout << ans << endl;


}
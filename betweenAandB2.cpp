#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int func(ll num, ll x){

    if(num >= 0){
        return num / x + 1;
    }
    else return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, x;
    cin >> a >> b >> x;

    cout << func(b, x) - func(a - 1, x) << endl;
}
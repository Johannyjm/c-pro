#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int digit_num(ll num){
    ll digits = 0;

    while(num > 0){
        num /= 10;
        digits++;
    }
    return digits;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll res = 1e9;

    for(int a = 1; a <= sqrt(N) + 1; ++a){

        if(N % a == 0){
            ll b = N / a;
            ll d_num = max(digit_num(a), digit_num(b));
            if(d_num < res) res = d_num;
        }
    }
    cout << res << endl;

}
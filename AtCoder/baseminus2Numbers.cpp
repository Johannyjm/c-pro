#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll calc_bm2num(int base[]){
    ll b = 1;
    ll res = 0;

    for (int i = 0; i < 30; ++i){
        res += base[i] * b;
        b *= -2;
    }
    return res;
}

void show_bm2num(int base[]){

    bool yet_flg = true;
    for(int i = 30; i >=0; --i){
        if(base[i]==0 && yet_flg) continue;
        else{
            yet_flg = false;
            cout << base[i];
        }
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    
    for (ll i = 0; i < (1<<25); ++i){
        int base[30] = {0};

        for(ll j = 0; j < 25; ++j){

            if(i & (1<<j)){
                base[j] = 1;
            }

        }

        if(calc_bm2num(base) == n){
            show_bm2num(base);
            return 0;
        }
    }
    cout << "end" << endl;
}
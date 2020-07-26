#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll last_gain = -1;
    ll first_bottom = -1;
    rep(i, n){
        cin >> a[i];
        if(i>0 && a[i] > a[i-1]) last_gain = i;
        if(first_bottom==-1 && i>0 && a[i] > a[i-1]) first_bottom = i-1;
    }
    if(first_bottom == -1){
        cout << 1000 << endl;
        return 0;
    }

    ll prev;
    if(first_bottom == 0) prev = a[0];
    else prev = a[first_bottom];

    ll money = 1000;
    ll stock = 0;
    for(ll i = first_bottom; i < n; ++i){
        if(prev < a[i]){
            ll gain = money / prev;
            stock += gain;
            money -= gain * prev;
        }

        if(prev > a[i]){
            money += prev * stock;
            stock = 0;
        }

        if(i == last_gain){
            money += stock*a[i];
            break;
        }
        prev = a[i];
    }

    cout << money << endl;

    return 0;
}
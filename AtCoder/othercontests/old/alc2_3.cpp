#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll maxh;
    cin >> maxh;

    bool flg=true;

    for (ll i = 1; i < n; ++i){
        ll h;
        cin >> h;
        if(maxh>h+1) flg=false;
        
        maxh = max(maxh, h);
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}
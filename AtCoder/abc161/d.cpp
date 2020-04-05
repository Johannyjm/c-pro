#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    if(k<10){
        cout << k << endl;
        return 0;
    }

    queue<ll> q;
    rep1(i, 10) q.push(i);

    ll cnt = 9;
    bool b_flg = false;
    while(!q.empty()){
        ll current = q.front();
        ll v = q.front() % 10;
        q.pop();
        
        rep(i, 3){
            ll nv = v+i-1;
            if(nv<0 || nv>=10) continue;

            q.push(current*10 + nv);
            ++cnt;

            if(cnt==k){
                cout << current*10 + nv << endl;
                return 0;
            }
        }
    }

    return 0;
}
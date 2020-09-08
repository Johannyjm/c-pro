#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, k;
    cin >> n >> m >> k;

    queue<ll> a, b;
    rep(i, n){
        ll aa;
        cin >> aa;
        a.push(aa);
    }
    rep(i, m){
        ll bb;
        cin >> bb;
        b.push(bb);
    }

    ll res = 0;
    ll now = 0;
    while(1){
        if(now > k){
            --res;
            break;
        }
        ll booka = 1001001001;
        ll bookb = 1001001001;
        if(!a.empty()) booka = a.front();
        if(!b.empty()) bookb = b.front();

        if(bookb==1001001001 || booka<=bookb){
            ++res;
            now += booka;
            if(!a.empty())a.pop();
        }
        else if(booka==1001001001 || booka>bookb){
            ++res;
            now += bookb;
            if(!b.empty())b.pop();
        }

        if(a.empty() && b.empty()) break;
    }

    cout << res << endl;



    return 0;
}
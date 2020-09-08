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
    rep(i, n) cin >> a[i];

    ll prev = a[0];
    ll curr;
    ll res1 = 0;
    if(prev == 0){
        prev = 1;
        ++res1;
    }

    rep1(i, n){
        curr = prev + a[i];
        if(curr == 0){
            if(prev < 0) curr = 1;
            else curr = -1;
            ++res1;
        }
        if(prev<0 && curr<0){
            res1 += 1 - curr;
            curr = 1;
        }
        if(prev>0 && curr>0){
            res1 += curr + 1;
            curr = -1;
        }

        prev = curr;
    }

    ll res2;
    if(a[0] > 0){
        prev = -1;
        res2 = a[0] + 1;
    }
    if(a[0] < 0){
        prev = 1;
        res2 = 1 - a[0];
    }
    if(a[0] == 0){
        prev = -1;
        res2 = 1;
    }
    
    rep1(i, n){
        curr = prev + a[i];
        if(curr == 0){
            if(prev < 0) curr = 1;
            else curr = -1;
            ++res2;
        }
        if(prev<0 && curr<0){
            res2 += 1 - curr;
            curr = 1;
        }
        if(prev>0 && curr>0){
            res2 += curr + 1;
            curr = -1;
        }

        prev = curr;
    }
    

    cout << min(res1, res2) << endl;

    return 0;
}
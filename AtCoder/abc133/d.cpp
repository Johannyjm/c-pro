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
    vector<ll> even_sm(n, 0), odd_sm(n, 0);
    
    ll sm = 0;
    rep(i, n){
        cin >> a[i];
        sm += a[i];
        if(i == 0) even_sm[i] = a[i];
        if(i > 0){
            even_sm[i] = even_sm[i-1];
            odd_sm[i] = odd_sm[i-1];

            if(i%2 == 0) even_sm[i] += a[i];
            else odd_sm[i] += a[i];
        }
    }

    vector<int> res(n);
    rep(i, n){
        if(i%2 == 0){
            ll sub = odd_sm[n-2] - odd_sm[i];
            if(i!=0) sub += even_sm[i-2];

            res[i] = sm - sub*2;
        }
        else{
            ll sub = even_sm[n-1] - even_sm[i];
            if(i!=1) sub += odd_sm[i-2];

            res[i] = sm - sub*2;
        }
    }

    rep(i, n) cout << res[i] << " ";
    cout << endl;

    return 0;
}
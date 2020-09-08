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

    sort(a.begin(), a.end(), greater<ll>());

    ll res = a[0];
    ll rest = n-2;
    int ptr = 1;
    while(rest){

        if(rest > 1){
            res += a[ptr] * 2;
            ++ptr;
            rest -= 2;
        }
        else{
            res += a[ptr];
            break;
        }
    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    ll sm = 0;
    ll res = 0;
    vector<ll> d;

    rep(i, n){
        sm += a[i];
        d.push_back(a[i]);
        if(sm > k){
            sm -= a[i];
            d.pop_back();
            res = i;
            break;
        }
    }

    int ptr = 0;
    rep(i, n){
        sm -= d.back();
        d.pop_back();

        for(int j = ptr; j < m; ++j){
            sm += b[j];
            if(sm>k){
                sm -= b[j];
                res += j;
                ptr = j;
                break;
            }
        }

    }
    cout << res << endl;


    return 0;
}
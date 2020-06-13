#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
 
#define SEG_LEN (1 << 18)
 
int seg[SEG_LEN * 2];
 
// one point
long long int get(int ind){
    ind += SEG_LEN;
    long long int sum = 0;
    sum += seg[ind];
    while(true){
        ind /= 2;
        if(ind == 0)break;
        sum += seg[ind];
    }
    return sum;
}
 
// range
void add(int l, int r, int x){
    l += SEG_LEN;
    r += SEG_LEN;
    while(l < r){
        if(l % 2 == 1){
            seg[l] += x;
            l++;
        }
        l /= 2;
        if(r % 2 == 1){
            seg[r-1] += x;
            r--;
        }
        r /= 2;
    }
}
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
 
    rep(i, n){
        add(i, i+1, a[i]);
    }
 
    rep(c, 200){
        if(c == k) break;
        vector<pair<ll, ll>> addd(n);
        rep(i, n){
            int l = max(i - get(i), 0ll);
            int r = min(i + get(i), n-1);
 
            addd[i] = make_pair(l, r);
        }

        vector<int> tmp(n);
        rep(i, n) tmp[i] = get(i);

        rep(i, n){
            int l = addd[i].first;
            int r = addd[i].second;
            add(l, r+1, 1);
        }

        rep(i, n){
            add(i, i+1, -tmp[i]);
        }
        bool flg = true;
        rep(i, n){
            if(get(i) != n){
                flg = false;
                break;
            }
        }

        if(flg) break;
    }


    rep(j, n-1){
    cout << get(j) << " ";
    }
    cout << get(n-1) << endl;
 
 
    return 0;
}
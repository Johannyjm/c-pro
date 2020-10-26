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


    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n){
        add(i, i+1, a[i]);
    }

    

    rep(i, k){
        rep(j, n){
            int l = max(0ll, j-a[j]);
            int r = min(n-1, j+a[j]);
            // cout << l << " " << r << endl;
            add(l, r+1, 1);
        }

        rep(j, n){
            // cout << get(j) << " " << a[j] << endl;
            a[j] = get(j)-a[j];
            add(j, j+1, a[j]-get(j));
        }
        
        bool flg = true;
        rep(j, n){
            if(get(j) != n){
                flg = false;
                break;
            }
        }

        if(flg) break;
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int MOD = 40000;  
ll seg[1<<18];  
  
// class FloatingMedian {  
void inc(int k, int left, int right, int x) {  
    if (left == right)  
        seg[k]++;  
    else {  
        int mid = (left+right)/2;  
        if (x <= mid)  
            inc(2*k+1, left, mid, x);  
        else  
            inc(2*k+2, mid+1, right, x);  
        seg[k] = seg[2*k+1] + seg[2*k+2];  
    }  
}  
  
void dec(int k, int left, int right, int x) {  
    if (left == right)  
        seg[k]--;  
    else {  
        int mid = (left+right)/2;  
        if (x <= mid)  
            dec(2*k+1, left, mid, x);  
        else  
            dec(2*k+2, mid+1, right, x);  
        seg[k] = seg[2*k+1] + seg[2*k+2];  
    }  
}  
  
ll get(int k, int left, int right, int x) {  
    if (left == right)  
        return left;  
    else {  
        int mid = (left+right)/2;  
        if (seg[2*k+1] >= x)  
            return get(2*k+1, left, mid, x);  
        else  
            return get(2*k+2, mid+1, right, x-seg[2*k+1]);  
    }  
}  
  
  
// public:  
//     long long getMedian(int seed, int mul, int add, int N, int K) {  
//         memset(seg, 0, sizeof(seg));  
  
//         vector<long long>t;  
//         t.push_back(seed);  
//         rep1(i, N)  
//             t.push_back((t[i-1]*mul+add)%MOD);  
  
//         long long ret = 0;  
//         rep(i, N){  
//             inc(0, 0, 65535, t[i]);  
//             if (i >= K)  
//                 dec(0, 0, 65535, t[i-K]);  
  
//             if (i >= K-1)  
//                 ret += get(0, 0, 65535, (K+1)/2);  
//         }  
//         return ret;  
//     }  
// };  


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    vector<ll> arr(k*k);
    ll res = 1ll<<60;
    int medidx = (k*k)/2;

    // vector<ll> cnt(40000, 0);
    // vector<map<ll, ll>> mp(40000);
    vector<ll> t;
    rep(i, k) rep(j, k){
        // mp[a[i][j] / 40000][a[i][j]] += 1;
        // cnt[a[i][j] / 40000] += 1;
        t.push_back(a[i][j]);
    }

    // sort(aa.begin(), aa.end(), greater<ll>());
    // res = min(res, aa[medidx]);

    // FloatingMedian fm;
    // for(auto e: t) cout << e << " ";
    cout << endl;
    memset(seg, 0, sizeof(seg)); 
    rep(i, k*k){  
        inc(0, 0, 40000, t[i]);  
    }
    res = get(0, 0, 40000, k*k-medidx);
    // cout << res << endl;
    // return 0;

    rep(u, n-k+1){
        if(u%2==0){
            rep1(l, n-k+1){

                rep(i, k){
                    ll tmp = a[u+i][l-1];
                    dec(0, 0, 40000, tmp);
                }

                rep(i, k){
                    ll tmp = a[u+i][l+k-1];
                    inc(0, 0, 40000, tmp);
                }

                res = min(res, get(0, 0, 40000, k*k-medidx));
                // int ptr = 0;
                // int sm = 0;
                // while(sm <= medidx){
                //     sm += cnt[ptr];
                //     ptr += 1;
                // }
                // --ptr;
            }
        }
        else{
            for(int l = n-k-1; l>=0; --l){
                
                rep(i, k){
                    ll tmp = a[u+i][l+k-1];
                    dec(0, 0, 40000, tmp);;
                }

                rep(i, k){
                    ll tmp = a[u+i][l-1];
                    inc(0, 0, 40000, tmp);
                }

                res = min(res, get(0, 0, 40000, k*k-medidx));
            }
        }
        if(u == n-k) continue;

        if(u%2 == 0){
            rep(j, k){
                ll tmp = a[u][n-k+j];
                dec(0, 0, 40000, tmp);;
            }

            rep(j, k){
                ll tmp = a[u+k][n-k+j];
                inc(0, 0, 40000, tmp);
            }

            res = min(res, get(0, 0, 40000, k*k-medidx));
        }

        else{
            rep(j, k){
                ll tmp = a[u][k];
                dec(0, 0, 40000, tmp);;
            }

            rep(j, k){
                ll tmp = a[u+k][j];
                inc(0, 0, 40000, tmp);
            }

            res = min(res, get(0, 0, 40000, k*k-medidx));
        }


    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(c, k){
        vector<int> imos(n+1, 0);
        rep(i, n){
            int from = max(0, i-a[i]);
            int to = min(n, i+a[i]+1);

            ++imos[from];
            --imos[to];        
        }

        rep1(i, n+1) imos[i] += imos[i-1];

        a = imos;

        bool flg = true;
        rep(i, n){
            if(a[i] != n){
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
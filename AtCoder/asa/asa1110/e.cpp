#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int res = 0;
    int len = 0;
    map<int, int> lstidx;
    int i = 0;
    while(i < n){
        // cout << a[i] << " ";
        if(lstidx[a[i]]==0){
            ++len;
            lstidx[a[i]] = i+1;
            res = max(res, len);
        }
        else{
            i = lstidx[a[i]];
            lstidx.clear();
            lstidx[a[i]] = i+1;
            len = 1;
        }
        ++i;
    }

    cout << res << endl;

    return 0;
}
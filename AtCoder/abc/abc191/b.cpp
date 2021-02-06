#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // vector<int> res;
    // rep(i, n){
    //     if(a[i] != x) res.push_back(a[i]);
    // }

    // rep(i, (int)res.size()-1) cout << res[i] << " ";
    // cout << res.back() << endl;

    rep(i, n){
        if(a[i] != x) cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
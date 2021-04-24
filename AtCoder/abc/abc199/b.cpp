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
    vector<int> a(n), b(n);
    int mxa = 0;
    int mnb = 10000;
    rep(i, n){
        cin >> a[i];
        mxa = max(mxa, a[i]);
    }
    rep(i, n){
        cin >> b[i];
        mnb = min(mnb, b[i]);
    }

    cout << max(0, mnb - mxa + 1) << endl;

    

    return 0;
}
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

    vector<int> h(n);
    rep(i, n) cin >> h[i];

    sort(h.begin(), h.end());
    int res = h[k-1] - h[0];
    
    rep(i, n-k+1){
        int sub = h[k-1+i] - h[i];
        res = min(res, sub);
    }

    cout << res << endl;

    return 0;
}
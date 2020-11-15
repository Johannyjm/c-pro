#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k, m;
    cin >> n >> k >> m;
    vector<int> a(n-1);
    int sm = 0;
    rep(i, n-1){
        cin >> a[i];
        sm += a[i];
    }

    int res = n*m - sm;
    if(res > k) cout << -1 << endl;
    else cout << max(0, res) << endl;



    return 0;
}
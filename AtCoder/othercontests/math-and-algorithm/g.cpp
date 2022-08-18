#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;

    int res = 0;
    rep1(k, n+1){
        
        if(k%x==0 || k%y==0) ++res;
    }

    cout << res << endl;

    return 0;
}
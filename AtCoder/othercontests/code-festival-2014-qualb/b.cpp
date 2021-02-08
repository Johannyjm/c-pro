#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    
    int cnt = 0;
    rep(i, n){
        int a;
        cin >> a;
        cnt += a;

        if(cnt >= k){
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;
}
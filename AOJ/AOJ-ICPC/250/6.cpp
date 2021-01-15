#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const int MAXN = 8000000;

    while(1){
        int m, n;
        cin >> m >> n;
        if(m == 0) break;

        vector<int> dp(MAXN, 0);
        int cnt = 0;
        for(int i = m; i < MAXN; ++i){
            if(dp[i] != 0) continue;
            for(int j = i; j < MAXN; j += i){
                dp[j] = 1;
            }
            ++cnt;
            if(cnt == n) break;
        }

        for(int i = m; i < MAXN; ++i){
            if(dp[i] == 0){
                cout << i << endl;
                break;
            }
        }
        
    }

    return 0;
}
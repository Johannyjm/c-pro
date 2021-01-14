#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> pollock, pollockodd;
    int now = 1;
    while(1){
        int p = now*(now+1)*(now+2)/6;
        if(p > 1000000) break;
        pollock.push_back(p);
        if(p % 2 == 1) pollockodd.push_back(p);
        ++now;
    }

    const int INF = 1001001001;
    vector<int> dp(1100000, INF), dpo(1100000, INF);
    dp[0] = 0;
    dpo[0] = 0;
    int n = pollock.size();
    int no = pollockodd.size();
    rep1(i, 1000100){
        rep(j, n){
            if(i-pollock[j] >= 0) dp[i] = min(dp[i], dp[i-pollock[j]] + 1);
        }
        rep(j, no){
            if(i-pollockodd[j] >= 0) dpo[i] = min(dpo[i], dpo[i-pollockodd[j]] + 1);
        }
    }

    while(1){
        int num;
        cin >> num;
        if(num == 0) break;

        cout << dp[num] << " " << dpo[num] << endl;
    }



    return 0;
}
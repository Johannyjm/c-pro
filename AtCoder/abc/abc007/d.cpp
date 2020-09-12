#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

ll ddp(ll s){
    if(s == 0) return 0;

    vector<ll> d;
    while(s){
        d.push_back(s % 10);
        s /= 10;
    }

    reverse(d.begin(), d.end());
    int n = d.size();

    ll dp[n][2][2] = {};
    if(d[0]==4 || d[0]==9){
        dp[0][0][0] = 0;
        dp[0][0][1] = 1;
    }
    else{
        dp[0][0][0] = 1;
        dp[0][0][1] = 0;
    }
    dp[0][1][0] = d[0];
    if(d[0] > 4){
        dp[0][1][1] = 1;
        --dp[0][1][0];
    }
    
    ll now = d[0];
    for(int i = 1; i < n; ++i){
        if(d[i]==4 || d[i]==9){
            dp[i][0][0] = 0;
            dp[i][0][1] = 1;
        }
        else{
            dp[i][0][0] = dp[i-1][0][0];
            dp[i][0][1] = dp[i-1][0][1];
        }

        now = now * 10 + d[i];

        dp[i][1][1] = dp[i-1][1][1] * 10 + dp[i-1][1][0] * 2 + dp[i-1][0][1] * d[i] + dp[i-1][0][0] * (d[i] > 4);
        dp[i][1][0] = now - dp[i][1][1];

    }


    return dp[n-1][0][1] + dp[n-1][1][1];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    cout << ddp(b) - ddp(a-1) << endl;

    return 0;
}

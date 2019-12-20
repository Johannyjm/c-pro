#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int dp[n] = {0};

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        if(i == p-1) dp[i] = 1;
        else dp[i] = 0;
    }

    int res = 0;
    for (int i = 0; i < n-1; ++i) {
        if(dp[i] == 1){
            res++;
            dp[i+1] = 0;
        }
    }
    cout << res << endl;


}
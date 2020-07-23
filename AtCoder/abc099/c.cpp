#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> use;
    use.push_back(1);

    int base6 = 6;
    while(base6 <= n){
        use.push_back(base6);
        base6 *= 6;
    }

    int base9 = 9;
    while(base9 <= n){
        use.push_back(base9);
        base9 *= 9;
    }

    sort(use.begin(), use.end());
    
    const int INF = 1001001001;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i < n+1; ++i){
        for(int val: use){
            if(i-val >= 0) dp[i] = min(dp[i], dp[i-val] + 1);
        }
    }

    cout << dp[n] << endl;


    return 0;
}

#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string l;
    cin >> l;
    int n = l.size();

    mint dp[n+1] = {};
    dp[1] = 3;
    mint pcnt = 1;
    rep1(i, n){
        if(l[i] == '1'){
            dp[i+1] = dp[i] * 3;
            ++pcnt;
        }
        else{
            mint m = 2;
            m = m.pow(pcnt.val()+1);
            dp[i+1] = dp[i] * 3 - m;
        }
    }

    cout << dp[n].val() << endl;

    return 0;
}
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int calcp(int num){
    int ret = 0;
    while(num){
        ret += num%2;
        num /= 2;
    }

    return ret;
}

int solve(int num){
    int ret = 1;
    int pcnt;
    while(num){
        pcnt = calcp(num);
        num %= pcnt;
        ++ret;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string x;
    cin >> x;

    int pcnt = 0;
    rep(i, n){
        if(x[i] == '1') ++pcnt;
    }

    string xr = x;
    reverse(xr.begin(), xr.end());

    int res = 0;
    int resplus = 0;
    int resminus = 0;
    rep(i, n){
        if(xr[i] == '1'){
            res += pow_mod(2, i, pcnt);
            res %= pcnt;
            resplus += pow_mod(2, i, pcnt+1);
            resplus %= pcnt+1;
            
            if(pcnt-1 == 0) continue;
            resminus += pow_mod(2, i, pcnt-1);
            resminus %= pcnt-1;
        }
    }
    // cout << res << endl;

    // int cnt = 1;
    // while(res){
    //     int pcnt = calcp(res);
    //     res %= pcnt;
    //     ++cnt;
    // }
    // cout << cnt << endl;

    rep(i, n){
        // cout << endl;
        if(x[i] == '1'){
            if(pcnt-1 == 0){
                cout << 0 << endl;
                continue;
            }
            int diff = pow_mod(2, n-i-1, pcnt-1);
            int num = (resminus + (pcnt-1) - diff) % (pcnt-1);
            // cout << num << endl;
            cout << solve(num) << endl;
        }
        else{
            int diff = pow_mod(2, n-i-1, pcnt+1);
            int num = (resplus + diff) % (pcnt+1);
            // cout << num << endl;
            cout << solve(num) << endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, a, b, c;
vector<int> l;
int rec(int i, int sma, int smb, int smc, int cost){
    if(i == n){
        int ret = abs(sma-a) + abs(smb-b) + abs(smc-c);
        if(min({sma, smb, smc}) == 0) ret = 1001001001;
        else ret -= 30;
        return ret;
    }

    int ret0 = rec(i+1, sma, smb, smc, cost);
    int ret1 = rec(i+1, sma+l[i], smb, smc, cost) + 10;
    int ret2 = rec(i+1, sma, smb+l[i], smc, cost) + 10;
    int ret3 = rec(i+1, sma, smb, smc+l[i], cost) + 10;

    return min({ret0, ret1, ret2, ret3});
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b >> c;
    l.resize(n);
    rep(i, n) cin >> l[i];

    cout << rec(0, 0, 0, 0, 0) << endl;


    return 0;
}
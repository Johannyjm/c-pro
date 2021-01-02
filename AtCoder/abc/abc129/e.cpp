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

    mint res = 0;
    mint pcnt = 0;
    rep(i, n){
        if(l[i] == '1'){
            res += mint(2).pow(pcnt.val()) * mint(3).pow(n-i-1);
            ++pcnt;
        }
    }
    res += mint(2).pow(pcnt.val());

    cout << res.val() << endl;

    return 0;
}
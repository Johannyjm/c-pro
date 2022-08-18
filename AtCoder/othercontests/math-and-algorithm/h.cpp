#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;

    int res = 0;
    rep1(a, n+1) rep1(b, n+1){

        if(a+b <= s) ++res;
    }

    cout << res << endl;

    return 0;
}
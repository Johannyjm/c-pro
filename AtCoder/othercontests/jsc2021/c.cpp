#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;



int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    int res = 1;
    for(int g = 2; g <= b; ++g){

        int l = 0;
        while(l < a) l += g;
        int r = l + g;
        if(a<=l && r<=b) res = max(res, g);
    }

    cout << res << endl;

    return 0;
}
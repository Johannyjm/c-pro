#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(true){
        int m, nmn, nmx;
        cin >> m >> nmn >> nmx;

        vector<int> p(m);
        rep(i, m) cin >> p[i];

        sort(p.begin(), p.end());

        int res = -1;
        int mx_diff= 0;

        for(int n = nmn; n <= nmx; ++n){

        }

    }

    return 0;
}
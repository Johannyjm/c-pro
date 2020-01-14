#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int p[n], q[n], num[n];
    rep(i, n) {
        cin >> p[n];
        num[n] = i+1;
    }
    rep(i, n) cin >> q[n];

    int pidx, qidx;

    do{
        bool flg = true;
        rep(i, n){
            if(p[i] == num[i]) flg = flg && true;
            else flg = false;
        }
        if(flg) pidx = 
    }

}
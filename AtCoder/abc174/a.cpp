#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l, r, d;
    cin >> l >> r >> d;

    int res = 0;
    for(int i = l; i <= r; ++i){
        if(i%d == 0)++res;
    }

    cout << res << endl;

    return 0;
}
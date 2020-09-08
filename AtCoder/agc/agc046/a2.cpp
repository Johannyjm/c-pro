#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;

    int res = 0;
    while(1){
        int now = x*res;
        if(now != 0 && now%360==0) break;
        ++res;
    }

    cout << res << endl;

    return 0;
}
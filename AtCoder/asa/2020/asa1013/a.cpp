#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 0;
    int ptr = 1;
    rep(i, n){
        int a;
        cin >> a;

        if(a != ptr) ++res;
        else ++ptr;
    }

    if(res == n) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}
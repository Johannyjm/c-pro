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
    rep(i, n){
        int v, w, x, y, z;
        cin >> v >> w >> x >> y >> z;

        if(v+w+x+y+z < 20) ++res;
    }

    cout << res << endl;

    return 0;
}
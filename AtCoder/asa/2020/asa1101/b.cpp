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
    int pt = 0;
    int px = 0;
    int py = 0;
    
    rep(i, n){
        int t, x, y;
        cin >> t >> x >> y;

        if(abs(x+y - (px+py)) > abs(t-pt) || (x+y)%2 != t%2){
            puts("No");
            return 0;
        }

        pt = t;
        px = x;
        py = y;
    }

    puts("Yes");

    return 0;
}
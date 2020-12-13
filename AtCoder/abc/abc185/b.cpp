#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, t;
    cin >> n >> m >> t;

    int prev = 0;
    int now = n;
    rep(i, m){
        int a, b;
        cin >> a >> b;

        now -= (a-prev);
        if(now <= 0){
            puts("No");
            return 0;
        }
        prev = b;

        now += b-a;
        now = min(now, n);
    }

    now -= (t-prev);
    
    if(now <= 0) puts("No");
    else puts("Yes");

    return 0;
}
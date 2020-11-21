#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d, t, v, n;
    cin >> a >> b >> c >> d >> t >> v >> n;

    int vt2 = v*v*t*t;
    rep(i, n){
        int x, y;
        cin >> x >> y;

        double dist12 = (a-x)*(a-x)+(b-y)*(b-y);
        double dist22 = (c-x)*(c-x)+(d-y)*(d-y);
        
        double dist = pow(dist12, 0.5) + pow(dist22, 0.5);

        if(pow(dist, 2) <= vt2){
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}
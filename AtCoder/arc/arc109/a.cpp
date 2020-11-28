#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    if(a==b){
        cout << x << endl;
        return 0;
    }

    if(a>b){
        int d = a-b;

        int res = y*d+x;
        rep(i, d){
            int sm = i*y;
            sm += (2*(d-i)-1)*x;
            res = min(res, sm);
        }

        cout << res << endl;
        return 0;
    }

    if(b>a){
        int d = b-a;
        int res = y*d + x;
        rep(i, d){
            int sm = i*y;
            sm += (2*(d-i)+1)*x;
            res = min(res, sm);
        }
        cout << res << endl;
    }

    return 0;
}
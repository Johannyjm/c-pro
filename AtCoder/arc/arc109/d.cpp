#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t--){
        ll a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        ll dfx = 0;
        ll dfy = 0;
        int lex = 0;
        int ley = 0;
        int cey = 0;
        int cey = 0;
        int rix = 0;
        int riy = 0
        if(a==c){
            dfx = a;
            cex = 0;
            c = 0;
            e -= dfx;
        }
        else if(c==e){
            dfx = c;
            c = 0;
            e = 0;
            a -= dfx;
        }
        else if(a==e){
            dfx = a;
            a = 0;
            e = 0;
            c -= dfx;
        }
        
        if(b==d){
            dfy = b;
            b = 0;
            d = 0;
            f -= dfy;
        }
        else if(d==f){
            dfy = d;
            d = 0;
            f = 0;
            b -= dfy;
        }
        else if(b==f){
            dfy = b;
            b = 0;
            f = 0;
            d -= dfy;
        }

        int ptn = -1;
        if()


    }

    return 0;
}
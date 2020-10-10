#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

bool check(int n){
    int cnt3 = 0;
    int cnt5 = 0;
    int cnt7 = 0;

    while(n){
        int d = n%10;
        if(d == 3) ++cnt3;
        if(d == 5) ++cnt5;
        if(d == 7) ++cnt7;

        n /= 10;
    }

    if(cnt3*cnt5*cnt7 > 0) return true;
    else return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll base = 333;
    int res = 0;
    while(base <= n){
        if(base%10 == 7){
            ll tmp = base;
            int cnt = 0;
            while(tmp%10==7){
                tmp /= 10;
                ++cnt;
            } 
            base /= pow(10, cnt);
            base *= pow(10, cnt);
            if(base == 0){
                base = 3;
                rep(_, cnt){
                    base *= 10;
                    base += 3;
                }
            }
            else{
                base += 2*pow(10, cnt);
                int m = 3;
                rep(_, cnt-1){
                    m *= 10;
                    m += 3;
                }
                base += m;
            }
        }
        else base += 2;
        if(check(base) && base <= n) ++res;
        // cout << base << " " << res << endl;
    }

    cout << res << endl;

    return 0;
}
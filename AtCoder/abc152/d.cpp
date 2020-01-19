#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int d(int n){
    int d = 1;
    int tmp = n;
    while(tmp/10){
        ++d;
        tmp/=10;
    }
    return d;
}

int le(int n){

    int dec = d(n);
    int de = 1;
    rep(i, dec-1) de *= 10;

    return n/de;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int keta = d(n);
    int nr = n%10;
    int nl = le(n);
    int add[] = {0, 0, 1, 11, 111, 1111};
    int keta_add[] = {0, 0, 1, 10, 100, 1000, 10000};
    

    int res = 0;
    rep1(i, n+1){
        int r = i%10;
        int l = le(i);

        if(r == 0) continue;

        if(l == r) ++res;
        res += add[keta];

        if(nl > r) res += keta_add[keta];
        if(nl < r) continue;
        if(nl == r){
            int tmp = n/10;
            tmp %= keta_add[keta+1];
            res += tmp;
            if(nr == l) ++res;
        }

    }
    cout << res << endl;

    return 0;
}
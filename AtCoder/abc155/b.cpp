#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
using ll = int_fast64_t;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    bool flg = true;
    rep(_, n){
        int a;
        cin >> a;
        if(a%2==0){
            if(a%3==0 || a%5==0){
                flg = flg && true;
            }
            else{
                flg = false;
            }
        }
    }
    if(flg) puts("APPROVED");
    else puts("DENIED");

    return 0;
}
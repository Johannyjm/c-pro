#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int d(int num){
    int ret = 0;
    while(num){
        ret += num%10;
        num /= 10;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n==1 || n==2 || n==3 || n==5){
        if(n==1) puts("Not Prime");
        else puts("Prime");
        return 0;
    }

    bool flg1, flg2, flg3;

    if(n%2) flg1 = true;
    else flg1 = false;

    if(n%10 != 5) flg2 = true;
    else flg2 = false;

    if(d(n)%3) flg3 = true;
    else flg3 = false;

    if(flg1 && flg2 && flg3) puts("Prime");
    else puts("Not Prime");

    return 0;
}
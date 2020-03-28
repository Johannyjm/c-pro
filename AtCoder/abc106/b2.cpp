#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int divisor(int num){
    int ret = 0;

    rep1(i, num+1){
        if(num%i==0) ++ret;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n <= 105){
        if(n == 105) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    int res = 1;
    for(int num = 106; num <= n; ++num){
        if(divisor(num)==8 && num%2==1) ++res;
    }

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int numd(int n){
    int ret = 0;
    for(int i = 1; i <= n; ++i){
        if(n%i==0) ++ret;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(n<105){
        cout << 0 << endl;
        return 0;
    }

    int res = 0;

    for (int i = 105; i <= n; ++i){
        if(i%2 && numd(i) == 8) ++res;
    }
    cout << res << endl;
}
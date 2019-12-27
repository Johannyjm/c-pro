#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    ll base = 2;
    string res ="";

    if(!n){
        puts("0");
        return 0;
    }

    while(n){
        if(n%base) res = "1" + res;
        else res = "0" + res;
        n = (n-abs(n%base)) / -2;
    }
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;

    if(a > b || (n==1&&a!=b)){
        cout << 0 << endl;
        return 0;
    }

    ll mn = a*(n-1) + b;
    ll mx = a + b*(n-1);

    cout << mx-mn+1 << endl;


    return 0;
}
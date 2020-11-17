#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll k = m/n;
    while(k > 1){
        if(m%k%k == 0) break;
        --k;
    }

    cout << k << endl;

    return 0;
}
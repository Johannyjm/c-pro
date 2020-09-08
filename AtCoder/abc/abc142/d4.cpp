#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    ll n = max(a, b);
    ll tmpa = a;
    ll tmpb = b;

    map<int, int> abp;
    
    for(int i = 2; i*i <= a; ++i){
        if(tmpa%i == 0){
            ++abp[i];
            while(tmpa%i==0) tmpa /= i;
        }
    }

    for(int i = 2; i*i <= b; ++i){
        if(tmpb%i == 0){
            ++abp[i];
            while(tmpb%i==0) tmpb /= i;
        }
    }

    int res = 1;
    for(int key = 2; key*key <= n; ++key){
        if(abp[key]>1) ++res;
    }

    cout << res << endl;
    
}
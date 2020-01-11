#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    ll n = max(a, b);
    ll tmpa = a;
    ll tmpb = b;

    int bucket[max(a, b)+1] = {0};
    for(int i = 2; i*i <= a; ++i){
        if(tmpa%i == 0){
            ++bucket[i];
            while(tmpa%i==0) tmpa /= i;
        }
    }

    for(int i = 2; i*i <= b; ++i){
        if(tmpb%i == 0){
            ++bucket[i];
            while(tmpb%i==0) tmpb /= i;
        }
    }

    int res = 1;
    for(int i = 2; i*i < n; ++i){
        if(bucket[i]>1) ++res;
    }

    cout << res << endl;
    
}
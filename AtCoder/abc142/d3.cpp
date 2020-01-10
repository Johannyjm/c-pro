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

    ll n = gcd(a, b);

    int res = 1;

    for(int i = 2; i <= n; ++i){
        if(a%i == 0 && b%i == 0){
            ++res;
            while(a%i==0) a /= i;
            while(b%i==0) b /= i;
        }
        else if(a%i==0){
            while(a%i==0) a /= i;
        }
        else if(b%i==0){
            while(b%i==0) b /= i;
        }
    }

    cout << res << endl;
}
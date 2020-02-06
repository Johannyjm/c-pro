#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

bool isprime(int n){
    if(n==1) return false;
    for (int i = 2; i*i <= n; ++i){
        if(n%i==0) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(isprime(n)) puts("YES");
    else puts("NO");


    return 0;
}
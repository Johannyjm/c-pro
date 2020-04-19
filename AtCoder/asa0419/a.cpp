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

    if(a==0 || b==0 || (a*b<0)) puts("Zero");
    else if(a>0 && b>0) puts("Positive");
    else{
        if((b-a)%2) puts("Positive");
        else puts("Negative");
    }

    return 0;
}
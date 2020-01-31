#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    if(a*b<0) {
        puts("Zero");
        return 0;
    }

    if(a>0 && b>0){
        puts("Positive");
        return 0;
    }

    if((b-a)%2) puts("Positive");
    else puts("Negative");

    return 0;
}
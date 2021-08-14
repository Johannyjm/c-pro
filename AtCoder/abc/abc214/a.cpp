#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    if(1<=n && n<=125) puts("4");
    if(126<=n && n<=211) puts("6");
    if(212<=n) puts("8");

    return 0;
}
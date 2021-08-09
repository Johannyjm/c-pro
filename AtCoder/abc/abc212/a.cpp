#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    if(0 < a && b == 0) puts("Gold");
    if(a == 0 && 0 < b) puts("Silver");
    if(0 < a && 0 < b) puts("Alloy");

    return 0;
}
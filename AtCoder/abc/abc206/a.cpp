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

    int p = (n * 108) / 100;

    if(p < 206) puts("Yay!");
    if(p == 206) puts("so-so");
    if(p > 206) puts(":(");

    return 0;
}
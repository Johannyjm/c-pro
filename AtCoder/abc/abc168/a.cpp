#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int d = n%10;

    if(d==2 || d==4 || d==5 || d==7 || d==9) puts("hon");
    else if(d==0 || d==1 || d==6 || d==8) puts("pon");
    else puts("bon");

    return 0;
}
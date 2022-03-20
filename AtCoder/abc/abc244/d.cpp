#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    char a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;

    if(a==x&&b==y&&c==z || a==z&&b==x&&c==y || a==y&&b==z&&c==x) puts("Yes");
    else puts("No");

    return 0;
}
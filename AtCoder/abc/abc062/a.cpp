#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int group(int num){
    if(num==2) return 2;
    if(num==4 || num==6 || num==9 || num==11) return 1;
    return 0;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    if(group(x)==group(y)) puts("Yes");
    else puts("No");
}
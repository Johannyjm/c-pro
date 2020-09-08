#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    int sum = 0;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
    }

    int cnt = 0;
    rep(i, n){
        if(4*a[i]*m >= sum) ++cnt;
    }
    
    if(cnt>=m) puts("Yes");
    else puts("No");


    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int cnt2d(int n){
    int cnt = 0;
    while(n%2==0){
        ++cnt;
        n /= 2;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 0;
    rep(i, n){
        int a;
        cin >> a;
        res += cnt2d(a);
    }
    cout << res << endl;
}
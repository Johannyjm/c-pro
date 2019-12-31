#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int res = 0;

    rep(i, n){
        int a;
        cin >> a;

        if(a%6==0) res += 3;
        else if(a%5==0) res += 2;
        else if(a%2==0 || a%3==2) ++res;

    }
    cout << res << endl;
}
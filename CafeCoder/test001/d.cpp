#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 1;
    for(int a = 2; a*a <= n; ++a){
        if(n % (a*a) == 0){
                // if(a*a == n) cout << a << endl;
                // else cout << a << " " << n/(a*a) << endl;
            res = a;
        }
    }

    if(res*res == n) cout << res << endl;
    else cout << res << " " << n/(res*res) << endl;

    return 0;
}
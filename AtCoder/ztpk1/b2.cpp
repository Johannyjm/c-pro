#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string a, b, c;
    cin >> n >> a >> b >> c;

    int res = 0;
    rep(i, n){
        if(a[i] == b[i]){
            if(b[i] == c[i]) res += 0;
            else ++res;
        }
        else{
            if(b[i] == c[i]) ++res;
            else if(a[i] == c[i]) ++res;
            else res += 2;
        }
    }

    cout << res << endl;

    return 0;
}
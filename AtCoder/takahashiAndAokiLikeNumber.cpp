#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, n;
    cin >> a >> b >> n;

    for (int i = n; i < n + a*b; ++i){
        if(i%a==0 && i%b==0){
            cout << i << endl;
            return 0;
        }
    }
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;

    for (int i = a; i <= b; ++i){
        if((a<=i && i<a+k) || (b-k<i && i<=b)) cout << i << endl;
    }
}
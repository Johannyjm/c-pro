#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, k;
    cin >> a >> b >> k;

    if(k <= a) cout << a-k << " " << b << endl;
    if(a<k && k <=a+b) cout << 0 << " " << a+b-k << endl;
    if(a+b < k) cout << 0 << " " << 0 << endl;

    return 0;
}
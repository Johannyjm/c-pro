#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k, x;
    cin >> k >> x;

    for(int i = x-k+1; i < x+k-1; ++i) cout << i << " ";
    cout << x+k-1 << endl;

    return 0;
}
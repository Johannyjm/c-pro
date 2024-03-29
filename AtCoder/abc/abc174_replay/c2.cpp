#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    int base = 7;
    if(base % k == 0){
        cout << 1 << endl;
        return 0;
    }
    rep1(i, k*2){
        base *= 10;
        base += 7;
        base %= k;

        if(base == 0){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
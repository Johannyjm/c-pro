#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x;
    cin >> x;
    
    int res = 0;
    int num = 1;
    while(num*(num+1) < 2*x){
        res = num;
        ++num;
    }
    cout << res+1 << endl;

    return 0;
}
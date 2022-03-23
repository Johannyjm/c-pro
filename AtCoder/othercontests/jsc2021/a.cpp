#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y, z;
    cin >> x >> y >> z;

    if((y*z)%x == 0){
        cout << (y*z) / x - 1 << endl;
    }
    else{
        cout << (y*z) / x << endl;
    }

    return 0;
}
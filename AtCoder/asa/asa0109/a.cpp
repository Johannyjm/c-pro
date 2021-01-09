#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w, a, b;
    cin >> w >> a >> b;

    if((a<=b && b<=a+w) || (b<=a && a<=b+w)){
        cout << 0 << endl;
        return 0;
    }

    if(a+w < b){
        cout << b - (a+w) << endl;
        return 0;
    }

    if(b+w < a){
        cout << a - (b+w) << endl;
        return 0;
    }


    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll s;
    cin >> s;

    ll a = s/1000000000 + 1;
    ll b = 1000000000 - s%1000000000;

    if(s==1000000000000000000){
        cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " " << 0 << " " << 1000000000 << endl;
        return 0;
    }
    cout << 0 << " " << 0 << " " << 1000000000 << " " << 1 << " " << b << " " << a << endl;


    return 0;
}
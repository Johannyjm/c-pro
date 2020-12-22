#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool valid10(int n){
    while(n){
        if(n%10 == 7) return false;
        n/=10;
    }
    return true;
}
bool valid8(int n){
    while(n){
        if(n%8 == 7) return false;
        n/=8;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int res = 0;
    rep1(i, n+1){
        if(valid10(i) && valid8(i)) ++res;
    }

    cout << res << endl;

    return 0;
}
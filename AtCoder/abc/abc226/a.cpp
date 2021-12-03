#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    cin >> x;
    int n = x.size();

    int res = 0;
    rep(i, n){
        if(x[i] == '.'){
            if(x[i+1] - '0' < 5){
                cout << res << endl;
            }
            else cout << res + 1 << endl;
            return 0;
        }
        res *= 10;
        res += x[i] - '0';
    }

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    string res = "";

    while(n){
        if(n % 2 == 0){
            n /= 2;
            res += 'B';
        }
        else{
            --n;
            res += 'A';
        }
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}
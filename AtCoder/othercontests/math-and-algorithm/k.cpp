#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    auto isprime = [](int k){
        if(k == 2) return true;
        for(int l = 2; l * l <= k; ++l){
            if(k % l == 0) return false;
        }
        return true;
    };

    for(int k = 2; k <= n; ++k){
        if(isprime(k)) cout << k << " ";
    }
    cout << endl;

    return 0;
}
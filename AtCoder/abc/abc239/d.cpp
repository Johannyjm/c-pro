#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool is_prime(int n){
    if(n == 1) return false;
    
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    for(int n = a; n <= b; ++n){
        bool uncaught = true;
        for(int m = c; m <= d; ++m){
            if(is_prime(n+m)){
                uncaught = false;
                break;
            }
        }
        if(uncaught){
            puts("Takahashi");
            return 0;
        }
    }

    puts("Aoki");

    return 0;
}
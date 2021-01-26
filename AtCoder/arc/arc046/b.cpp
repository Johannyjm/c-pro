#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    
    if(a == b){
        if(n <= a) puts("Takahashi");
        else{
            if(n % (a+1) == 0) puts("Aoki");
            else puts("Takahashi");
        }
        return 0;
    }

    if(n <= a){
        puts("Takahashi");
        return 0;
    }
    if(n <= b){
        puts("Aoki");
        return 0;
    }

    if(a > b) puts("Takahashi");
    else puts("Aoki");

    

    return 0;
}
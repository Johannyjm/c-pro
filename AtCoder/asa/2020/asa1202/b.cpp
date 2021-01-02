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
    
    for(int i = 2; i < n; ++i){
        if(n%i == 0){
            puts("NO");
            return 0;
        }
    }

    puts("YES");

    return 0;
}
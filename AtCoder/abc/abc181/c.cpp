#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    for(int i = 0; i < n-2; ++i){
        for(int j = i+1; j < n-1; ++j){
            for(int k = j+1; k < n; ++k){

                if((y[j]-y[i])*(x[k]-x[j]) == (y[k]-y[j])*(x[j]-x[i])){
                    puts("Yes");
                    return 0;
                }
            }
        }
    }

    puts("No");

    return 0;
}
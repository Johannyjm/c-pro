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
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    int k;
    cin >> k;
    map<int, int> mp;
    ++mp[a];
    ++mp[b];
    rep(i, k){
        int p;
        cin >> p;
        --p;

        ++mp[p];
        if(mp[p] > 1){
            puts("NO");
            return 0;
        }        
    }

    puts("YES");
    
    return 0;
}
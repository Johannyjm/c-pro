#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
   
vector<ll> lunlun;
void dfs(ll n){
    if(n > 40000000000) return;
    lunlun.push_back(n);
    if(lunlun.size() > 500001) return;
    int d = n%10;
    for(ll i = 0; i <= 9; ++i){
        if(d-1 <= i && i <= d+1){
            ll nxt = n*10 + i;
            dfs(nxt);
        }
    }
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    for(ll i = 1; i <= 9; ++i) dfs(i);

    sort(lunlun.begin(), lunlun.end());

    cout << lunlun[k-1] << endl;

    return 0;
}
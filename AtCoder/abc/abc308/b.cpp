#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<string> c(n), d(m);
    vector<int> p(m+1);
    rep(i, n) cin >> c[i];
    rep(i, m) cin >> d[i];
    rep(i, m+1) cin >> p[i];

    unordered_map<string, int> price;
    rep(i, m){
        price[d[i]] = p[i+1];
    }

    int res = 0;
    rep(i, n){
        if(price[c[i]] == 0){
            res += p[0];
        }
        else{
            res += price[c[i]];
        }
    }

    cout << res << endl;


    return 0;
}
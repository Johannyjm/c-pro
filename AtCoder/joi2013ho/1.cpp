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
    
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> comped;
    int cnt = 1;
    rep1(i, n){
        if(a[i] != a[i-1]) ++cnt;
        else{
            comped.push_back(cnt);
            cnt = 1;
        }
    }
    if(cnt != 0) comped.push_back(cnt);


    if(n < 4){
        cout << n << endl;
        return 0;
    }

    int res = 0;
    if(comped.size() < 3){
        rep(i, comped.size()) res += comped[i];
    }
    else{
        rep(i, comped.size()-2){
            res = max(res, comped[i] + comped[i+1] + comped[i+2]);
        }
    }

    cout << res << endl;

    return 0;
}
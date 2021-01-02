#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k, s;
    cin >> n >> k >> s;

    vector<int> res(n);
    rep(i, n){
        if(i < k) res[i] = s;
        else{
            if(s == 1000000000) res[i] = s-1;
            else res[i] = s+1;
        }
    }

    rep(i, n) cout << res[i] << " ";
    cout << endl;


    return 0;
}
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
    
    int mx = -1;
    rep(i, n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    vector<int> drop(mx+10, 0);
    rep(i, n){
        int num = a[i];

        int b = 1;
        while(num*b <= mx){
            ++drop[num*b];
            b++;
        }
    }

    int res = 0;
    rep(i, n){
        if(drop[a[i]] < 2){
            ++res;
        }
    }
    
    cout << res << endl;

    return 0;
}
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
    vector<int> l(2*n);
    rep(i, 2*n) cin >> l[i];

    sort(l.begin(), l.end(), greater<int>());
    
    int res = 0;
    rep(i, n){
        res += min(l[2*i], l[2*i+1]);
    }

    cout << res << endl;

    return 0;
}
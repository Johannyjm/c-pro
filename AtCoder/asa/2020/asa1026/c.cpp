#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k, s;
    cin >> n >> k >> s;

    if(s!=1000000000){
        rep(_, k) cout << s << " ";
        rep(_, n-k) cout << 1000000000 << " ";
        cout << endl;
    }
    else{
        rep(_, k) cout << s << " ";
        rep(_, n-k) cout << 999999999 << " ";
        cout << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;


    string al = "zabcdefghijklmnopqrstuvwxy";
    string res = "";

    while(n){
        res += al[n%26];
        
        if(n%26!=0)n /= 26;
        else n = n/26 - 1;
    }

    reverse(res.begin(), res.end());

    cout << res << endl;


    return 0;
}
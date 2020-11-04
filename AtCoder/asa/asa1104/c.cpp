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

    string res = "";
    while(n){
        --n;
        char c = n%26 + 'a';
        res += c;
        n /= 26;
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}
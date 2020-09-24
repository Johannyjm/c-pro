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

    if(7<=n%10 && n%10 <=9) cout << (n/10+1)*100 << endl;
    else cout << n/10*100 + n%10*15 << endl;

    return 0;
}
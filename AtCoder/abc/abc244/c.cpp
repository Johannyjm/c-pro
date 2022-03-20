#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<bool> seen(2*n+2, false);
    int now = 1;
    while(1){
        while(seen[now]) ++now;
        cout << now << endl;
        seen[now] = true;
        
        int aoki;
        cin >> aoki;
        seen[aoki] = true;
        if(aoki == 0) break;
    }

    return 0;
}
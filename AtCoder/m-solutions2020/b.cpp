#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if(a<b && b<c){
        puts("Yes");
        return 0;
    }

    if(a < b){
        if(c * pow(2, k) > b) puts("Yes");
        else puts("No");
        return 0;
    }

    int cnt = 0;
    while(b <= a){
        b *= 2;
        ++cnt;
    }

    if(cnt >= k){
        if(k==cnt){
            if(b < c) puts("Yes");
            else puts("No");
            return 0;
        }
        puts("No");
        return 0;
    }

    if(c * pow(2, k-cnt) > b) puts("Yes");
    else puts("No");



    return 0;
}
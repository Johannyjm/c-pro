#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int a, b, c;
bool is_ng(int num){
    if(num==a || num==b || num==c) return true;
    else return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> a >> b >> c;

    if(is_ng(n)){
        puts("NO");
        return 0;
    }

    int now = 0;
    rep(_, 100){
        if(now+1==n || now+2==n || now+3==n){
            puts("YES");
            return 0;
        }

        if(!is_ng(now + 3)) now += 3;
        else{
            if(!is_ng(now + 2)) now += 2;
            else{
                if(!is_ng(now + 1)) now += 1;
                else{
                    puts("NO");
                    return 0;
                }
            }
        }
    }

    puts("NO");

    return 0;
}
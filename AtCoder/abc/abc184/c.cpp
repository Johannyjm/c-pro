#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool legal(int a, int b, int c, int d){
    if(a+b == c+d) return true;
    if(a-b == c-d) return true;
    if(abs(a-c)+abs(b-d) <= 3) return true;

    return false;
}

int solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(a==c && b==d) return 0;
    if(legal(a, b, c, d)) return 1;
    if((a+b)%2 == (c+d)%2) return 2;

    for(int x = a-3; x <= a+3; ++x){
        for(int y = b-3; y <= b+3; ++y){
            if(!legal(a, b, x, y)) continue;

            if(legal(x, y, c, d)) return 2;
        }
    }

    return 3;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cout << solve() << endl;

    return 0;
}
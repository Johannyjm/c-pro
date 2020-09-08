#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    --a;
    --b;
    --c;
    --d;

    string s;
    cin >> s;

    if(c < b){
        bool flg = true;
        for(int i = a; i < c-1; ++i){
            if(s[i]=='#' && s[i+1]=='#') flg = false;
        }
        for(int i = b; i < d-1; ++i){
            if(s[i]=='#' && s[i+1]=='#') flg = false;
        }

        if(flg) puts("Yes");
        else puts("No");
        return 0;
    }
    
    if(b<c && c<d){
        bool flg = true;
        for(int i = a; i < d-1; ++i){
            if(s[i]=='#' && s[i+1]=='#') flg = false;
        }

        if(flg) puts("Yes");
        else puts("No");
        return 0;
    }

    if(d<c){
        bool flg1 = true;
        for(int i = a; i < c-1; ++i){
            if(s[i]=='#' && s[i+1]=='#') flg1 = false;
        }

        bool flg2 = false;
        for(int i = b; i < d-2; ++i){
            if(s[i]=='.' && s[i+1]=='.' && s[i+2]=='.') flg2 = true;
        }

        if(flg1 && flg2) puts("Yes");
        else puts("No");
    }

    return 0;
}
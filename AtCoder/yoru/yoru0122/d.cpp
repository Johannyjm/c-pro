#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

char check(char a, char b){
    if(a == b) return a;
    if(a == 'R'){
        if(b == 'P') return b;
        else return a;
    }
    if(a == 'S'){
        if(b == 'R') return b;
        else return a;
    }
    if(a == 'P'){
        if(b == 'S') return b;
        else return a;
    }

    return a;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string now = s + s;
    rep(i, k){
        string nxt = "";
        rep(j, n){
            nxt += check(now[2*j], now[2*j+1]);
        }

        now = nxt + nxt;
    }

    cout << now[0] << endl;

    return 0;
}
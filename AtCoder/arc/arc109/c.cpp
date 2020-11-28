#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

char judge(char a, char b){
    if(a==b) return a;
    if(a=='P'){
        if(b=='R') return a;
        if(b=='S') return b;
    }
    if(a=='R'){
        if(b=='S') return a;
        if(b=='P') return b;
    }
    if(a=='S'){
        if(b=='P') return a;
        if(b=='R') return b;
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

    string curr = s+s;
    
    rep(i, k){
        string nxt = "";
        
        for(int j = 0; j < 2*n; j += 2){
            char c = judge(curr[j], curr[j+1]);
            nxt += c;
        }

        curr = nxt+nxt;
    }

    cout << curr[0] << endl;

    return 0;
}
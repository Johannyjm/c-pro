#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string st;
    cin >> st;
    
    int s=0;
    int n=0;
    int w=0;
    int e=0;
    rep(i, st.size()){
        if(st[i] == 'S') ++s;
        if(st[i] == 'N') ++n;
        if(st[i] == 'W') ++w;
        if(st[i] == 'E') ++e;
    }

    bool sn;
    bool we;

    if(s){
        if(n) sn = true;
        else sn = false;
    }
    else{
        if(n) sn = false;
        else sn = true;
    }

    if(w){
        if(e) we = true;
        else we = false;
    }
    else{
        if(e) we = false;
        else we = true;
    }

    if(sn && we) puts("Yes");
    else puts("No");

    return 0;
}
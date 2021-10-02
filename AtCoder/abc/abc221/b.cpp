#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    if(s == t){
        puts("Yes");
        return 0;
    }

    int n = s.size();
    rep(i, n-1){

        string tmp = s;
        swap(tmp[i], tmp[i+1]);
        if(t == tmp){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    const string k = "keyence";
    int ptr = 0;
    vector<int> rem(n, 0);

    rep(i, n){
        if(ptr==7) rem[i] = 1;
        if(s[i] == k[ptr]) ++ptr;
        else rem[i] = 1;
    }

    int cnt = 0;
    rep(i, n-1){
        if(rem[i]!=rem[i+1]){
            ++cnt;
            if(cnt==2 && rem[i+1]==1) ++cnt;
        }
    }


    if(ptr==7 && cnt<=2) puts("YES");
    else puts("NO");

    return 0;
}
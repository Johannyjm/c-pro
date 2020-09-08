#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    vector<int> abc(3, 0);
    rep(i, n) ++abc[s[i] - 'a'];

    if(n <= 3){
        if(n==1) puts("YES");
        if(n==2){
            if(abc[0]<2 && abc[1]<2 && abc[2]<2) puts("YES");
            else puts("NO");
        }
        if(n==3){
            if(abc[0]==1 && abc[1]==1 && abc[2]==1) puts("YES");
            else puts("NO");
        }

        return 0;
    }
    
    if(max({abc[0], abc[1], abc[2]}) - min({abc[0], abc[1], abc[2]}) < 2) puts("YES");
    else puts("NO");

    return 0;
}
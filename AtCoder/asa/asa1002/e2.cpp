#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    rep(i, n){
        int start = -1;
        for(int j = i+1; j < n; ++j){
            if(s[i] == s[j]){
                start = j;
                int cnt = 0;
                while(start+cnt < n && i+cnt < start && s[i+cnt] == s[start+cnt]){
                    ++cnt;
                }

                res = max(res, cnt);
            }
        }   


        
    }

    cout << res << endl;

    return 0;
}
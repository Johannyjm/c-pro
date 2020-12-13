#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    
    int cnt1 = 0; // 101010...
    int cnt2 = 0; // 010101...

    rep(i, n){
        if(i%2 == 0){
            if(s[i] == '0') ++cnt1;
            else ++cnt2;
        }
        else{
            if(s[i] == '0') ++cnt2;
            else ++cnt1;
        }
    }

    cout << min(cnt1, cnt2) << endl;

    return 0;
}
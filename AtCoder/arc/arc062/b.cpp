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

    int pcnt = 0;
    int gcnt = 0;
    int res = 0;
    rep(i, n){
        if(s[i] == 'g'){
            if(pcnt < gcnt){
                ++res;
                ++pcnt;
            }
            else{
                ++gcnt;
            }
        }
        else{
            if(pcnt < gcnt){
                ++pcnt;
            }
            else{
                --res;
                ++gcnt;
            }
        }
    }

    cout << res << endl;

    return 0;
}
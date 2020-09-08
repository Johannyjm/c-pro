#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string acce = "b";
    rep(i, n){
        if(i%3==1){
            acce = 'a' + acce + 'c';
        }
        if(i%3==2){
            acce = 'c' + acce + 'a';
        }
        if(i%3==0 && i!=0){
            acce = 'b' + acce + 'b';
        }
        
        if(acce == s){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
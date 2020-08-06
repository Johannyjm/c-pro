#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int passed = 0;
    int b_idx = 1;
    rep(i, n){
        if(s[i] == 'a'){
            if(passed < a+b){
                puts("Yes");
                ++passed;
            }
            else puts("No");
        }
        else if(s[i] == 'b'){
            if(passed < a+b && b_idx <= b){
                puts("Yes");
                ++b_idx;
                ++passed;
            }
            else puts("No");
        }
        else puts("No");
    }

    

    return 0;
}
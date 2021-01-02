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

    string now = s;
    while(now.size() > 0){
        int d = now.size();
        if(d <= 7){
            if(now=="dream" || now=="erase" || now=="eraser" || now=="dreamer"){
                puts("YES");
            }
            else puts("NO");

            return 0;
        }

        if(now.substr(d-5, 5)=="dream") now = now.substr(0, d-5);
        else if(now.substr(d-5, 5)=="erase") now = now.substr(0, d-5);
        else if(now.substr(d-6, 6)=="eraser") now = now.substr(0, d-6);
        else if(now.substr(d-7, 7)=="dreamer") now = now.substr(0, d-7);
        else{
            puts("NO");
            return 0;
        }
    }

    return 0;
}
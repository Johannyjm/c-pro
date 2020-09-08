#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if(a.length() > b.length()){
        puts("GREATER");
        return 0;
    }
    else if(a.length() < b.length()) {
        puts("LESS");
        return 0;
    }
    else{
        for (int i = 0; i < a.length(); ++i){
            if(a[i] == b[i]) continue;

            if(a[i] > b[i]){
                puts("GREATER");
                return 0;
            }
            else{
                puts("LESS");
                return 0;
            }
        }
    }
    puts("EQUAL");
    return 0;
}
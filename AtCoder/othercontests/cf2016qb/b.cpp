#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int passed_all = 0;
    int passed_abroad = 0;

    rep(i, n){
        if(s[i]=='c') puts("No");

        if(s[i]=='a'){

            if(passed_all<a+b){
                puts("Yes");
                ++passed_all;
            }
            else puts("No");
        }

        if(s[i]=='b'){
            if(passed_all<a+b && passed_abroad<b){
                puts("Yes");
                ++passed_all;
                ++passed_abroad;
            }
            else puts("No");
        }
    }

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 4;
    int a_prev, a_current;
    rep(i, n){
        rep(j, n){
            if(j==0) {
                cin >> a_prev;
            }
            else {
                cin >> a_current;
                if(a_prev==a_current){
                    puts("CONTINUE");
                    return 0;
                }
                a_prev = a_current;
            }
        }
    }

    puts("GAMEOVER");

    return 0;
}
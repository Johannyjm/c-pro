#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;

    int player = 1; // 1: Takahashi, 2: Aoki
    rep(_, k){
        if(player){
            if(a%2) a -= 1;
            b += a/2;
            a /= 2;
        }

        else{
            if(b%2) b -= 1;
            a += b/2;
            b /= 2;
        }

        player = 1 - player; // Switch the player
    }

    cout << a << " " << b << endl;

    return 0;
}
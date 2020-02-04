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

    int player = 1;

    while(1){
        if(player){
            if(n <= a){
                puts("Ant");
                return 0;
            }
            else n -= a;
        }

        else{
            if(n <= b){
                puts("Bug");
                return 0;
            }
            else n -= b;
        }

        player = 1 - player;
    }

    return 0;
}
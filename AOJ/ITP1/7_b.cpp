#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n, x;
        cin >> n >> x;

        if(n==0) return 0;

        int res = 0;
        for(int a = 1; a <= n-2; ++a){
            for(int b = a+1; b <= n-1; ++b){
                for(int c = b+1; c <= n; ++c){
                    if(a==b || b==c || c==a) continue;

                    if(a+b+c == x) ++res;
                }
            }
        }

        cout << res << endl;

    }

    return 0;
}
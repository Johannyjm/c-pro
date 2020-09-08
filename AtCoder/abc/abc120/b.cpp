#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;

    int cnt = 1;
    for(int i = min(a, b); i > 0; --i){
        if(a%i==0 && b%i==0){
            if(cnt==k){
                cout << i << endl;
                return 0;
            }

            ++cnt;
        }
    }

    return 0;
}
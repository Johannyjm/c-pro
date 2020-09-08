#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, l;
    string s;
    cin >> n >> l >> s;

    int res = 0;
    int current = 1;
    rep(i, n){
        if(s[i] == '+'){
            ++current;

            if(current > l){
                current = 1;
                ++res;
            }
        }
        else --current;
    }
    
    cout << res << endl;


    return 0;
}
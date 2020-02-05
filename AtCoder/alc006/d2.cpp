#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int sum = 0;
    int dig = 0;
    rep1(i, n){
        sum += i;
        if(sum>=n) {
            dig = i;
            break;
        }
    }
    int sub = n-sum;

    rep(i, 1<<dig){
        int cand = 0;
        rep(j, dig){
            
            if(i &(1<<j)){
                cand += j;
            }

        }
        if(cand==sub){
            rep(j, dig){
                if(i &(1<<j)){
                    cout << j << endl;
                }                
            }
        }
    }


    return 0;
}
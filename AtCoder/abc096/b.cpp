#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int abc[3];
    int max_idx = 0;
    int max_val = -1;
    rep(i, 3){
        cin >> abc[i];
        if(max_val < abc[i]){
            max_idx = i;
            max_val = abc[i];
        }
    }
    int k;
    cin >> k;

    rep(i, k){
        abc[max_idx] *= 2;
    }
    
    cout << abc[0] + abc[1] + abc[2] << endl;
}
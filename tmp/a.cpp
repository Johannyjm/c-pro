#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    rep(i, n)cin >> a[i];

    int count_max = 0;

    rep(i, n){
        int count = 0;
        int l = k;
        for(int j = i+1; j < n; ++j){
            if(a[j] == a[i] + l){
                l += k;
                count ++;
            }
        }
        if(count_max < count)count_max = count;
    }

    if(count_max == 0)cout << -1 << endl;
    else cout << count_max + 1 << endl;

}
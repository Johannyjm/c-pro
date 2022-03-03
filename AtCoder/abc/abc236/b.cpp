#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    rep(i, 4*n-1){
        int a;
        cin >> a;
        ++cnt[a];
    }

    for(auto k: cnt){
        if(k.second == 3){
            cout << k.first << endl;
            return 0;
        }
    }

    return 0;
}
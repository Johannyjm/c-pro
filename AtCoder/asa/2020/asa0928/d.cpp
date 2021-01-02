#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> cnt(10, vector<int>(10, 0));
    rep1(i, n+1){
        int r = i%10;
        int l = 0;
        int num = i;
        while(num){
            l = num%10;
            num /= 10;
        }

        ++cnt[l][r];
    }

    int res = 0;
    rep1(l, 10) rep1(r, 10){
        res += cnt[l][r]*cnt[r][l];
    }
    cout << res << endl;

    return 0;
}
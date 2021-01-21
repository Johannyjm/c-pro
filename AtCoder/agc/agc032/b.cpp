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
    vector<vector<int>> is_ng(n, vector<int>(n+1, 0));
    int sm = n + ((n%2==0)? 1: 0);
    for(int i = 1; i <= n/2; ++i){
        int j = sm - i;
        is_ng[i][j] = 1;
    }

    vector<int> a, b;
    for(int i = 1; i <= n; ++i){
        for(int j = i + 1; j <= n; ++j){
            if(is_ng[i][j]) continue;
            a.push_back(i);
            b.push_back(j);
        }
    }

    int m = a.size();
    cout << m << endl;
    rep(i, m) cout << a[i] << " " << b[i] << endl;

    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());

    vector<map<int, int>> count1(k), count2(k);
    rep(i, n){
        ++count1[i%k][a[i]];
        ++count2[i%k][b[i]];
    }

    if(count1 == count2) puts("Yes");
    else puts("No");

    return 0;
}
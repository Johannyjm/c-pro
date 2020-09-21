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
    vector<int> a(n);
    vector<int> order(n);
    rep(i, n){
        cin >> a[i];
        order[a[i]-1] = i;
    }

    rep(i, n) cout << order[i] << " ";
    cout << endl;

    cout << n + rec(0) << endl;




    return 0;
}
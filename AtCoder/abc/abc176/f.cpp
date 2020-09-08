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
    vector<int> a(3*n);
    rep(i, 3*n) cin >> a[i];

    int l = a.back();

    rep(i, n-1){
        int start = 3*i;
        int end = start + 5;
        map<int, int> mp;
        for(int i = start; i < end; ++i){
            
        }
    }

    return 0;
}
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
    rep(i, n) cin >> a[i];
 
    vector<int> box(n, 0);
    for(int i = n-1; i >= 0; --i){
        int sm = 0;
        int ptr = i;
        while(ptr < n){
            sm += box[ptr];
            ptr += i+1;
        }
 
        if(sm%2 ^ a[i]) box[i] = 1;
    }

    vector<int> res;
    rep(i, n){
        if(box[i]) res.push_back(i+1);
    }

    cout << res.size() << endl;
    rep(i, res.size()) cout << res[i] << " ";
    cout << endl;
  
    return 0;
}
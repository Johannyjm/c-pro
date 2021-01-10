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

    vector<int> a(n), b(n);
    unordered_map<int, int> mp;
    rep(i, n){
        cin >> a[i] >> b[i];
        ++mp[a[i]];
        ++mp[b[i]];
    }

    unordered_set<int> res, rej;
    rep(i, n){
        if(res.count(a[i])){
            if(res.count(b[i])) res.insert(b[i]);
            else res.insert(b[i]);
        }
        else{
            if(res.count(b[i])) res.insert(a[i]);
            else{
                if(mp[a[i]] < mp[b[i]]) res.insert(a[i]);
                else if(mp[a[i]] > mp[b[i]]) res.insert(b[i]);
                else rej.insert(i);
            }
        }
    }

    

    cout << res.size() << endl;

    return 0;
}
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
    vector<string> s(n), t(n);
    rep(i, n) cin >> s[i] >> t[i];

    unordered_set<string> used;
    rep(i, n){
        
        if(used.count(s[i])){
            if(used.count(t[i])){
                puts("No");
                return 0;
            }
            else{
                used.insert(t[i]);
                continue;
            }
        }
        if(used.count(t[i])){
            used.insert(s[i]);
            continue;
        }
        int count_s = 0;
        int count_t = 0;
        rep(j, n){
            if(i == j) continue;
            if(s[i] == s[j] || s[i] == t[j]) ++count_s;
            if(t[i] == s[j] || t[i] == t[j]) ++count_t;
        }

        if(count_s >= count_t) used.insert(t[i]);
        else used.insert(s[i]);
    }

    puts("Yes");
    
    return 0;
}
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
    
    vector<int> c(n);
    rep(i, n) cin >> c[i];

    vector<pair<int, int>> comped;
    comped.push_back(make_pair(c[0], 1));
    rep1(i, n){
        if(i%2 == 0){
            if(comped.back().first == c[i]) ++comped.back().second;
            else comped.push_back(make_pair(c[i], 1));
        }
        else{
            if(comped.back().first == c[i]) ++comped.back().second;
            else{
                comped.back().first = c[i];
                ++comped.back().second;
            }
        }

        if(comped.size() > 1){
            if(comped[comped.size()-2].first == comped.back().first){
                comped[comped.size()-2].second += comped.back().second;
                comped.pop_back();
            }
        }
    }

    int res = 0;
    rep(i, n){
        if(comped[i].first == 0) res += comped[i].second;
    }

    cout << res << endl;

    return 0;
}
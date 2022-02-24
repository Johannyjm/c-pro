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
    
    vector<pair<int, int>> rlc;
    int a;
    cin >> a;
    rlc.push_back({a, 1});

    int res = 1;
    cout << res << "\n";

    rep1(i, n){
        int a;
        cin >> a;

        if(a == rlc.back().first){
            ++rlc.back().second;
            ++res;

            if(rlc.back().first == rlc.back().second){
                res -= rlc.back().second;
                rlc.pop_back();
            }
        }
        else{
            rlc.push_back({a, 1});
            ++res;
        }

        cout << res << "\n";
    }

    return 0;
}
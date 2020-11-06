#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    if(k > (n-1)*(n-2)/2){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> res;
    for(int i = 2; i <= n; ++i){
        res.push_back({1, i});
    }

    int ex = (n-1)*(n-2)/2 - k;
    int cnt = 0;
    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
            if(i <= j) continue;

            res.push_back({i, j});
            ++cnt;

            if(cnt == ex) break;
        }
        if(cnt == ex) break;
    }

    cout << res.size() << endl;
    for(auto e: res){
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}

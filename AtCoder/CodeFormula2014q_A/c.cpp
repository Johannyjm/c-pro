#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for(int i = 0; i < n; ++i) for(int j = 0; j < k; ++j) cin >> a[i][j];
    
    map<int, int> seen;
    for(int i = 0; i < n; ++i){
        int pass = (k+(n-i)-1) / (n-i);
        vector<int> cand;
        for(int j = 0; j < pass; ++j){
            if(seen[a[i][j]] > 0) continue;
            cand.push_back(a[i][j]);
            ++seen[a[i][j]];
        }

        sort(cand.begin(), cand.end());

        for(int j = 0; j < cand.size()-1; ++j) cout << cand[j] << " ";
        cout << cand.back() << endl;

        k -= cand.size();
    }

    return 0;
}

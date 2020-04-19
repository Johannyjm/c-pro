#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        if(p[i] == m){
            cout << m << endl;
            return 0;
        }
    }

    vector<int> half;
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            half.push_back(p[i]+p[j]);
            if(p[i]+p[j] == m){
                cout << m << endl;
                return 0;
            }
        }
    }
    rep(i, n) half.push_back(p[i]);

    sort(half.begin(), half.end());
    rep(i, half.size()){
        cout << half[i] << " ";
    }
    cout << endl;
    int res = 0;
    rep(i, half.size()){
        int target = half[i];

        int ok = 0;
        int ng = half.size();

        if(target+half[ok] > m) continue;

        if(target+half[ok] == m){
            cout << m << endl;
            return 0;
        }

        while(abs(ng-ok) > 1){
            
            int mid = (ok + ng) / 2;

            if(target+half[mid] == m){
                cout << m << endl;
                return 0;
            }
            // cout << ok << ng << mid << target << half[mid] << endl;
            if(target+half[mid] > m) ng = mid;
            else ok = mid;
        }
        
        res = max(res, target+half[ok]);
        cout << target + half[ok] << " " << res << endl;
    }

    cout << res << endl;

    return 0;
}
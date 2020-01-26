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
    rep(i, n) cin >> p[i];

    vector<int> half;
    rep(i, n){
        rep(j, n+1){
            int one = p[i];
            int two;
            if(j==n) two = 0;
            else two = p[j];

            if(one+two > m) continue;
            if(one+two == m) {
                cout << m << endl;
                return 0;
            }


            half.push_back(one + two);
        }
    }

    vector<int> remain(half.size());
    rep(i, half.size()){
        remain[i] = m - half[i];
    }

    sort(half.begin(), half.end());


    int res = 0;
    rep(i, remain.size()){
        int l = 0;
        int r = half.size();
        while(r-l>1){
            int mid = (l+r) / 2;

            if(half[mid] > remain[i]){
                r = mid;
            }

            else if(half[mid] == remain[i]) {
                // cout << half[mid] << " " << remain[i] << endl;
                cout << m << endl;
                return 0;
            }

            else{
                res = max(res, half[mid]+(m-remain[i]));
                l = mid;
            }
        }
    }
    cout << res << endl;

    return 0;
}
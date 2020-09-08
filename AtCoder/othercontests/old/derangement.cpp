#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; ++i) cin >> p[i];

    int res = 0;
    bool conflg = false;
    int concnt = 1;

    for (int i = 0; i < n; ++i){
        if(p[i]-1 == i){
            res++;
            if(conflg) concnt++;
            conflg = true;
        }
        else {
            if(conflg && concnt > 1){
                res--;
                concnt = 1;
            } 
            conflg = false;
        }
    }
    if(conflg && concnt > 1) res--;
    cout << res << endl;
}
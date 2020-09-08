#include <bits/stdc++.h>
using namespace std;

bool isSquared(int num){
    for(int i = 1; i <= num; ++i){
        if(i*i == num) return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    int x[n][d];
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < d; ++j) cin >> x[i][j];
    }
    
    int res = 0;
    for (int i = 0; i < n-1; ++i){
        for (int j = i+1; j < n; ++j){
            int distance_sq = 0;
            for (int dim = 0; dim < d; ++dim){
                distance_sq += abs(x[i][dim]-x[j][dim]) * abs(x[i][dim]-x[j][dim]);
            }
            
            if(isSquared(distance_sq)) res++;
        }
    }
    cout << res << endl;
}